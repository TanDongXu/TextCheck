#include <iostream>
#include<string>
#include"MD5_generator.h"
#include"md5CreateTrie.h"
#include"Trie.h"

using namespace std;

int main(void)
{
	Trie *trie = new Trie();

	//dataBase dialogue create trie
	dataBaseFile_to_trie("File/dataBase.txt", trie);
	//input file search from trie
	excel_dataBaseFile_cmp("File/input.txt",trie);

	return 0;
}

