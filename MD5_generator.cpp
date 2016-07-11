#include"MD5_generator.h"
//md5 init
void Md5::Md5_init()
{
	if(!MD5_Init(&_md5_ctx))
	{
		std::cout<<"MD5 Init Error!"<< std::endl;
	}
	memset(_md5Result, 0, sizeof(_md5Result));
}//end of md5 init

//getMd5
std::string Md5::getMD5(std::string inputStr)
{
	if(inputStr.size() <= 0)
	{
		std::cout<<"getMD5:InputStr is NULL"<< std::endl;
		return " ";
	}

	//must do it
	Md5_init();
	MD5_Update(&_md5_ctx, inputStr.c_str(), inputStr.size());
	MD5_Final(_md5Result,&_md5_ctx);
	return changeToHex(_md5Result);
}//end of getMd5

//changeToHex
std::string Md5::changeToHex(unsigned char* cStr)
{
	if(NULL == cStr)
	{
		std::cout<<"changeToHex:cStr is NULL"<< std::endl;
		exit(0);
	}
	std::string tmpStr;
	char tmpChar[33];
	for(int i = 0; i < 16; i++)
	{
		sprintf(tmpChar,"%02X", cStr[i]);
		tmpStr += tmpChar;
	}
	return lower_to_upper(tmpStr);
}//end of changeToHex

//Lower case to upper case
std::string Md5::lower_to_upper(std::string& inputStr)
{
	int length  = inputStr.size();
	if(length <= 0)
	{
		std::cout<<"lower_To_uper: Input Error!"<<std::endl;
		exit(0);
	}

	for(int i = 0; i < length; i++)
	{
		if(inputStr[i] != ' ' && inputStr[i] >= 'a' && inputStr[i] <= 'z')
		{
			inputStr[i] -= 32;
		}else if(inputStr[i] == ' ')
		{
			std::cout<<"lower_to_upper: Input is not a continuous string!"<< std::endl;
		}
	}

	return inputStr;
}//end of lower_to_upper
