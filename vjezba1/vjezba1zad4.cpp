#include <iostream>
using namespace std;

int& at(int niz[], int i)
{
	return niz[i];
}

int main()
{
	int niz[] = { 1,2,3,4,5,6 };
	int i = 0;
	cout << "Prije: " << niz[i] << endl;
	at(niz, i)++;
	cout << "Poslije: " << niz[i] << endl;
	return 0;
}
