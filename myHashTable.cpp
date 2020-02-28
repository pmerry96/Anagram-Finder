//
// Created by pmerry on 10/12/2019.
//
#include<iostream>
#include<vector>
#include<string>
#include<cmath>
using namespace std;
class myHashTable {

private:
	vector<vector<string>> hashtable;
	int loaded;
	
public:
	myHashTable(vector<string> wordlist) {
		loaded = 0;
		hashtable = vector<vector<string>>(2 * wordlist.size(), vector<string>(0));
		cout << "adding" << endl;
		for (auto iter = wordlist.begin(); iter < wordlist.end(); iter++) {
			string word = *iter;
			add(word); //add each word to the hash table
		}
		cout << "done adding" << endl;
	}
	
	unsigned long long int hashword(string &word) {
		vector<int> lettercount(26, 0);
		for (auto i = word.begin(); i < word.end(); i++) {
			int letterindex = *i - 'a'; //this subs ascii 'a' so that letters index 0-25
			lettercount[letterindex]++; //count how many times each letter appears
		}
		long long int sum = 0, x = 3, exp = 0;
		string str = "";
		for(char i : lettercount)
		{
			str += i;
		}
		hash<string> hashfxn;
		sum = hashfxn(str);
		/*
		for (int i : lettercount) {
			sum += i * (int) pow(x, exp);
			exp++;
		}
		 */
		return sum;
	}
	
	bool find(string &word) {
		unsigned long long int index = hashword(word) % hashtable.size();
		for (auto iter = hashtable[index].begin(); iter < hashtable[index].end(); iter++) {
			if (word == *iter) {
				return (true);
			}
		}
		return (false);
	}
	
	void add(string word) {
		if (!find(word)) {
			unsigned long long int index = hashword(word) % hashtable.size();
			hashtable[index].push_back(word);
			loaded++;
		}
	}
	
	void remove(string word) {
		if (find(word)) {
			unsigned long long int index = hashword(word) % hashtable.size();
			auto iter = hashtable[index].begin();
			for (; iter < hashtable[index].end(); iter++) {
				if (*iter == word) {
					iter->erase();
					loaded--;
				}
			}
		}
	}
	
	vector<string> getchain(string word) {
		unsigned long long int index = hashword(word) % hashtable.size();
		//this should return a vector of strings
		cout << hashtable[index].size() << endl;
		vector<string> anagrams;
		for(auto iter = hashtable[index].begin(); iter < hashtable[index].end(); iter++)
		{
			if(hashword(word) == hashword(*iter))
			{
				anagrams.push_back(*iter);
			}
		}
		return (anagrams);
	}
};