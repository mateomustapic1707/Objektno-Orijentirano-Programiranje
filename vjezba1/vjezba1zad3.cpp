#include <iostream>
#include <cctype>
#include <string>

using namespace std;

int main()
{
	string s;
	cout << ("Unesi jedan redak teksta: \n") << endl;
	getline(cin, s);

	for (char& c : s)
	{
		if (isalpha(c))
		{
			 c = toupper(c);
		}
		else if (isdigit(c))
		{
			c = '*';
		}
		else if (c == ' ' || c == '\t')
		{
			c = '_';
		}
	}
	cout << "Zamijenjeni  string: \n" << s << endl;
	return 0;
}
