#include <bits/stdc++.h>
using namespace std;

void remove_words(string str)
{
	//input string stream which will divide words in a string based on spaces
	istringstream in_string(str);
	//to store the unique words in the string
	unordered_set<string> words;

	do{
		string word;
		in_string>>word;
		while(words.find(word) == words.end())
		{
			cout<<word<<" ";
			words.insert(word);
		}

	}while(in_string);
}

int main()
{
	string word;
	cout<<"enter the string"<<endl;
	getline(cin, word);
	remove_words(word);
	return 0;
}
