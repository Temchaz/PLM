// ConsoleApplication6.1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <string>

int main()
{
	using namespace std;
	string word;
	getline(cin, word, '@');
	int word_size = word.size();
	for (int i = 0; i < word_size; i++) {
		char ch = word[i];
			if (isdigit(ch))
				continue;
			else if (islower(ch))
				ch = toupper(ch);
			else if (isupper(ch))
				ch = tolower(ch);
			cout << ch;
		}
	return 0;
}

