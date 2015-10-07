#include "rpi.h"

char* CTools::getmacaddress() //http://www.codeguru.com/Cpp/I-N/network/networkinformation/article.php/c5451
{
	static char retval[20];
	//...Set up for infomation out
	ifreq ifr;
	char if_name[BUFF_SIZE_S];
	strcpy ( if_name , "eth0" );
	size_t if_name_len=strlen(if_name);
	if (if_name_len<sizeof(ifr.ifr_name)) {
	    memcpy(ifr.ifr_name,if_name,if_name_len);
	    ifr.ifr_name[if_name_len]=0;
	} else {
		printf ( "[CTools::getmacaddress] Address too long %i ;\n",errno);
	    return NULL;
	}

	//...Open a socket 
	int fd=socket(AF_UNIX,SOCK_DGRAM,0);
	if (fd==-1) {
	    printf ( "[CTools::getmacaddress] Socket open fail %i\n",errno);
	    return NULL;
	}

	//...Grab the address
	if (ioctl(fd,SIOCGIFHWADDR,&ifr)==-1) {
	    int temp_errno=errno;
	    close(fd);
	    printf ( "[CTools::getmacaddress] ioctl fail %i\n",temp_errno);
	    perror ( "ioctl: ");
	    return NULL;
	}
	close(fd);

	//...Convert the address
	const unsigned char* mac=(unsigned char*)ifr.ifr_hwaddr.sa_data;
	sprintf(retval , "%02X:%02X:%02X:%02X:%02X:%02X\n",  mac[0],mac[1],mac[2],mac[3],mac[4],mac[5]);

	return retval;
}

char* CTools::md5buffer(CBuffer *buff)
{
	static char a[33];
	CalculateMD5(buff->data, buff->count, a);
	return a;
}

char* CTools::md5string(char *str)
{
	static char a[33];
	CalculateMD5(str, (int)strlen(str), a);
	return a;
}

unsigned int CTools::ip2uint(char *ip)
{
	return inet_addr(ip);
}

char* CTools::uint2ip(unsigned int ip)
{
	IN_ADDR a;
	a.s_addr = (u_long)ip;
	return inet_ntoa(a);
}

void CTools::encryptedbuffer(CBuffer *buff, char*key)
{
	char *inp = buff->data;
	unsigned int inplen = buff->count;
	char KeyBox[257];
	int keylen = min_rpi ((int)strlen(key), 256);
	if(keylen <= 0)return;
	unsigned long i, j, t, x;
	char temp;
	i = j = t = 0;
	for(i = 0; i < 256; i++)
		KeyBox[i] = (char)i;
	for(i = 0; i < 256; i++)
	{
		j = (j + (unsigned long) KeyBox[i] + key[i % keylen]) % 256;
		temp =  KeyBox[i];
		KeyBox[i] = KeyBox[j];
		KeyBox[j] =  temp;
	}
	i = j = 0;
	for(x = 0; x < inplen; x++)
	{
		i = (i + 1U) % 256;
		j = (j + (unsigned long) KeyBox[i]) % 256;
		temp = KeyBox[i];
		KeyBox[i] = KeyBox[j] ;
		KeyBox[j] = temp;
		t = ((unsigned long) KeyBox[i] + (unsigned long) KeyBox[j]) %  256 ;
		inp[x] = (inp[x] ^ KeyBox[t]);
	}
}

bool CTools::comparematch(char*string, char*wild)
{
	char *cp = 0, *mp = 0;
	while ((*string) && (*wild != '*')) {
		if((*wild != *string) && (*wild != '?')) {
			return 0;
		}
		wild++;
		string++;
	}
	while (*string) {
		if (*wild == '*') {
			if(!*++wild) {
				return 1;
			}
			mp = wild;
			cp = string+1;
		} else if ((*wild == *string) || (*wild == '?')) {
			wild++;
			string++;
		} else {
			wild = mp;
			string = cp++;
		}
	}
	while (*wild == '*') {
		wild++;
	}
	return !*wild;
}
unsigned int CTools::adler32(CBuffer*buff)
{
	char*data = buff->data;
	unsigned int len = buff->count;
	unsigned int a = 1, b = 0;
	while (len) {
		unsigned tlen = len > 5550 ? 5550 : len;
		len -= tlen;
		do {
			a += *data++;
			b += a;
		} while (--tlen);
		a = (a & 0xffff) + (a >> 16) * (65536-65521);
		b = (b & 0xffff) + (b >> 16) * (65536-65521);
	}
	if (a >= 65521)
		a -= 65521;
	b = (b & 0xffff) + (b >> 16) * (65536-65521);
	if (b >= 65521)
		b -= 65521;
	return b << 16 | a;
}

HANDLE CTools::BinOpen(char*filename, int mode)
{
	char * access;
	access = "a+b" ;
	if(mode == 0) access = "rb"; //..Read only
	if(mode == 1) access = "wb"; //..Write only
	// FILE *fopen(const char *filename, const char *mode);
	return fopen(filename, access );
}

bool CTools::BinClose(HANDLE hwnd)
{
	 if(fclose(hwnd))return true;
	 return false;
}

int CTools::BinWrite(HANDLE hwnd, CBuffer*in)
{
	int a = (int)fwrite( 	( in->data + in->readpos ),
					sizeof(char),
					( in->count-in->readpos ),
					hwnd );
	return (int)a;
}
int CTools::BinRead(HANDLE hwnd, int size, CBuffer*out)
{
	char*b = new char[size];
	// size_t fread(void *ptr, size_t size_of_elements, size_t number_of_elements, FILE *a_file);
	// 
	int a = (int)fread( 	b,
					sizeof(char),
					size,
					hwnd);	
	out->StreamWrite(b, a);
	delete b;
	return a;
}

int CTools::BinGetPos(HANDLE hwnd)
{
	return ftell(hwnd);
}

int CTools::BinSetPos(HANDLE hwnd, int offset)
{
	return fseek(hwnd, offset , SEEK_SET);
}

int CTools::BinFileSize(HANDLE hwnd)
{
	int fileSize = 0,ops =ftell (hwnd);
	
	fseek(hwnd, 0 , SEEK_END);
	fileSize = ftell(hwnd);
	fseek(hwnd, ops , SEEK_SET);

	return fileSize;
}

