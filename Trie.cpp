#include"Trie.h"

//Trie constructor
Trie::Trie()
{
	pRoot = new TrieNode();
	//vQueue.clear();
}//end of Trie

//destructor
Trie::~Trie()
{
	delete pRoot;
}//end of ~Trie

//Tire insert
void Trie::trie_insert(std::string inputStr)
{
	int length = inputStr.size();
	//if inputStr is NULL or the length is more than md5's length
	if( length <= 0 || length > 32)
	{
		std::cout<<"trie_insert: inuputStr Error!"<< std::endl;
		return;
	}

	int index;
	TrieNode* pNode = pRoot, *pNew;
	for(int i = 0; i < length; i++)
	{
		/*char A~Z put in 0~25 and char 0~9 put in 26~35*/
		if(inputStr[i] >= 'A' && inputStr[i] <='Z')
		{
			index = inputStr[i] - 'A';
		}else if(inputStr[i] >= '0' && inputStr[i] <= '9')
		{
			index = inputStr[i] - '0' + 26;
		}else
		{
			std::cout<<"trie_insert:Md5 input Error!"<<std::endl;
			exit(0);
		}

		if(NULL == pNode->nextBranch[index])
		{
			pNew = (TrieNode*) malloc(sizeof(TrieNode));
			pNew->word = inputStr[i];
			for(int j = 0; j < MaxBranchNum; j++)
			{
				pNew->nextBranch[j] = NULL;
			}

			pNode->nextBranch[index] = pNew;
			pNode = pNode->nextBranch[index];
		}else
		{
			pNode = pNode->nextBranch[index];
		}
	}//end for
}// end of Trie insert

//Trie search
bool Trie::trie_search(std::string inputStr)
{
	int length = inputStr.size();
	if(length <= 0 || length > 32)
	{
		std::cout<<"trie_search: inputStr Error!"<< std::endl;
		return false;
	}

	int index;
	TrieNode*pNode = pRoot;
	for(int i = 0; i < length; i++)
	{
		/*char A~Z put in 0~25 and char 0~9 put in 26~35*/
		if(inputStr[i] >= 'A' && inputStr[i] <='Z')
		{
			index = inputStr[i] - 'A';
		}else if(inputStr[i] >= '0' && inputStr[i] <= '9')
		{
			index = inputStr[i] - '0' + 26;
		}else
		{
			std::cout<<"trie_search:Md5 input Error!"<<std::endl;
			exit(0);
		}

		if(NULL == pNode->nextBranch[index])
			return false;
		else if(inputStr[i] == pNode->nextBranch[index]->word)
		{
			pNode = pNode->nextBranch[index];

		}else
		{
			return false;
		}

	}//end for
	return true;
}// end of Trie search

//printf Trie
//void Trie::dfs_printTrie(TrieNode* pNode)
//{
//	if(NULL == pNode)
//	{
//		std::cout<<"dfs_printTrie: Trie input Error!"<< std::endl;
//		return;
//	}
//
//	vQueue.push_back(pNode);
//	//if(pNode->){}
//}
