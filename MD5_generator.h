/*
 * MD5_generator.h
 *
 *  Created on: Jul 4, 2016
 *      Author: tdx
 */

#ifndef MD5_GENERATOR_H_
#define MD5_GENERATOR_H_

#include<iostream>
#include<openssl/md5.h>
#include<string>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>


/*md5 class call function from openssl/md5.h*/
class Md5
{
public:
	void Md5_init();
	std::string getMD5(std::string inputStr);

private:
	std::string changeToHex(unsigned char* cStr);
	std::string lower_to_upper(std::string& inputStr);

private:
	MD5_CTX _md5_ctx;
	unsigned char _md5Result[16];

};//end of class md5


#endif /* MD5_GENERATOR_H_ */
