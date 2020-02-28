//
// Created by pmerry on 10/12/2019.
//
#include"anagram.cpp"

int main()
{
	vector<string> words;
	vector<string> anagrams;
	string inputWord;
	words=loadWordlist("wordlist.txt");
	char keepon = 'y';
	while(keepon != 'n')
	{
	    cout << "Find single-word anagrams for the following word: ";
	    cin >> inputWord;
	    anagrams = anagram(inputWord, words);
	    for (int i=0; i<anagrams.size(); i++)
	    {
		cout << anagrams[i] << endl;
	    }
	    cout << " Would you like to keep going?" << endl;
	    cin >> keepon;
	}
	return 0;
}
