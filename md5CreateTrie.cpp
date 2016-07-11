#include"md5CreateTrie.h"

//adjust Sequential
void adjustSequent(string inputStr[], int length)
{
	string tmpStr;
	tmpStr = inputStr[0];
	for(int i = 1; i < length; i++)
	{
		inputStr[i - 1] = inputStr[i];
	}

	inputStr[length - 1] = tmpStr;
}// end of adjustSequent


//read dialogue and transform to md5, then create trie
void dataBaseFile_to_trie(string fileName, Trie* trie)
{
	//open file
	ifstream file(fileName.c_str());
	if(NULL == trie)
	{
		cout<<"dataBaseFile_to_trie: trie is NULL"<<endl;
		exit(0);
	}

	Md5* dialogueMd5 = new Md5();
	string szDialogue[6];
	string szSixDialogue;
	bool bIsBegin = true;

	if(!file.is_open())
	{
		std::cout<<"dataBaseFile_to_trie: File Open Failed!"<<std::endl;
		exit(0);
	}else
	{
		//traverse file
		while(!file.eof())
		{
			//first time read dialogue
			if(bIsBegin)
			{
				for(int j = 0; j < 6; j++)
				{
					if(!file.eof())
					{
					   getline(file, szDialogue[j]);
					   szSixDialogue += szDialogue[j];
					}else break;
				}
				bIsBegin = false;

			}else
			{
				//clear string
				szSixDialogue.clear();
				getline(file, szDialogue[0]);
				//next six dialogue
				adjustSequent(szDialogue, 6);
				for(int k = 0; k < 6; k++)
				{
					szSixDialogue += szDialogue[k];
				}
			}
			//six dialogue transform to md5, and insert to trie
			trie->trie_insert(dialogueMd5->getMD5(szSixDialogue));
		}//end of while
	}

	file.close();
	delete dialogueMd5;
	//cout<<"end of dataBaseFile_to_trie"<<endl;
}//end of dataBaseFile_to_trie

//read input file and search from trie
void excel_dataBaseFile_cmp(string fileName,Trie* trie)
{
	ifstream file(fileName.c_str());
	if(NULL == trie)
	{
		cout<<"excel_dataBaseFile_cmp: trie is NULL"<<endl;
		exit(0);
	}

	Md5* dialogueMd5 = new Md5();
	string szDialogue[6];
	string szSixDialogue;
	bool bIsSearchSuccess = false;
	bool bIsBegin = true;
	if(!file.is_open())
	{
		std::cout<<"excel_dataBaseFile_cmp: File Open Failed!"<<std::endl;
		exit(0);
	}else
	{
		while(!file.eof())
		{
			if(bIsBegin)
			{
				for(int i = 0; i < 6; i++)
				{
					if(!file.eof())
					{
						getline(file, szDialogue[i]);
						szSixDialogue += szDialogue[i];
					}else break;
				}
				bIsBegin = false;
			}else
			{
				//clear string
				szSixDialogue.clear();
				getline(file, szDialogue[0]);
				//next six dialogue
				adjustSequent(szDialogue, 6);
				for(int k = 0; k < 6; k++)
				{
					szSixDialogue += szDialogue[k];
				}
			}
			//seearch in trie
			bIsSearchSuccess = trie->trie_search(dialogueMd5->getMD5(szSixDialogue));
			if(!bIsSearchSuccess)
			{
				//search no success
				//add to dataBase
				//add to trie
				trie->trie_insert(dialogueMd5->getMD5(szSixDialogue));
			}else
			{
				//success
				//do not insert to dataBase
				//copy to a txt
				ofstream output("File/repeatDialogue.txt",ios::app);
				if(output.is_open())
				{
					for(int i = 0; i < 6; i++)
					{
						output<<szDialogue[i];
						output<<"\n";
					}
				}else
				{
					cout<<"excel_dataBaseFile_cmp:output File open Error!"<<endl;
					exit(0);
				}
				output.close();
			}
		}//end of while
	}
	file.close();
	delete dialogueMd5;
	//cout<<"end of excel_dataBaseFile_cmp"<<endl;
}


