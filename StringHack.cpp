#include <iostream>
#include <string>
#include <cstring>

using namespace std;

void getInput(const string & type, string & s)
{
	cout << "Enter string (" << type << ") : ";
	getline(cin, s);
}


bool strIsPermutation(const string & s1, const string & s2)
{
	// Assume stirng only has a ASCII chars;
	
	if (s1.length() != s2.length())
		return false;

	int * chars = new int[128];

	const char *str1 = s1.c_str();

	for(int i = 0; i < s1.length(); ++i)
	{
		++chars[str1[i]];
	}

	bool is_perm = true;
	const char *str2 = s2.c_str();
	for(int i = 0; i < s2.length(); ++i)
	{
		--chars[str2[i]];
		if(chars[str2[i]] < 0)
		{
			is_perm = false;
			break;
		}
	}

	delete [] chars;

	return is_perm;
}

int main(int argc, char **argv)
{

	// Example 1 : Demonstrate is string 1 is a permutation of char in string 2
	{
		string s1;
		string s2;
		getInput("string 1 for permutation", s1);
		getInput("string 2 for permutation", s2);

		strIsPermutation(s1, s2)?(cout << "string 2 is permutation of s1" << endl): \
			                 (cout << "string 2 is not a permutation of s1" << endl);
	}

	return 0;
}
