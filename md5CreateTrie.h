/*
 * md5CreateTrie.h
 *
 *  Created on: Jul 5, 2016
 *      Author: tdx
 */

#ifndef MD5CREATETRIE_H_
#define MD5CREATETRIE_H_

#include<string>
#include<fstream>
#include<iostream>
#include"Trie.h"
#include"MD5_generator.h"

using namespace std;

void dataBaseFile_to_trie(string fileName, Trie* trie);
void excel_dataBaseFile_cmp(string fileName,Trie* trie);

#endif /* MD5CREATETRIE_H_ */
