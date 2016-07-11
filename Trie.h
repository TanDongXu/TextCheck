/*
 * Trie.h
 *
 *  Created on: Jul 5, 2016
 *      Author: tdx
 */

#ifndef TRIE_H_
#define TRIE_H_

#include<iostream>
#include<vector>
#include<string.h>
#include<stdlib.h>

//the max branch of Trie
#define MaxBranchNum 36

//define TrieNode
class TrieNode
{
public:
	TrieNode():word(' ')
    {
		memset(nextBranch, NULL, sizeof(TrieNode*) * MaxBranchNum);
    }

public:
	char word;
	TrieNode* nextBranch[MaxBranchNum];

};//end of class TrieNode

//class Trie
class Trie
{
public:
	Trie();
	~Trie();
	void trie_insert(std::string inputStr);
	bool trie_search(std::string inputStr);
	//void dfs_printTrie(TrieNode* pNode);

private:
	TrieNode* pRoot;
	//std::vector<TrieNode*> vQueue;

};//end of class Trie



#endif /* TRIE_H_ */
