/*
 * Name: Philip Merry
 * Date Submitted:
 * Assignment Name: Anagram finder
 */

#include <iostream>
#include <fstream>
//#include <vector>
//#include <string>
#include<cmath>
//#include <unordered_map>
#include"myHashTable.cpp"

using namespace std;

vector<string> loadWordlist(string filename)
{
	vector<string> words;
	ifstream inFile;
	string word;
	inFile.open(filename);
	if(inFile.is_open())
	{
		while(getline(inFile,word))
		{
			if(word.length() > 0)
			{
				words.push_back(word);
			}
		}
		inFile.close();
	}
	return words;
}

/*Implement the following function:
  anagram() takes a word (string) and a wordlist of all words (vector of strings)
  and builds a dictionary/map where the key is a specific number of times each
  letter occurs in a word and the associated value is a vector of strings
  containing all words using those letters (anagrams).
  The value returned is a vector of strings containing the corresponding
  set of anagrams
*/
//Implement this function
vector<string> anagram(string word, vector<string> wordlist)
{
	//hash the words in the wordlist
	myHashTable hashTable(wordlist);
	return(hashTable.getchain(word));
}

