#include <iostream>
using namespace std;

int* fibonaci(int n)
{
	if (n <= 0)
	{
		return nullptr;
	}
	int* niz = new int[n];
	niz[0] = 1;
	if (n > 1)
	{
		niz[1] = 1;
	}
	for (int i = 2; i < n; i++)
	{
		niz[i] = niz[i - 1] + niz[i - 2];
	}
	return niz;
}

int main()
{
	int n;
	cout << "Unesite broj elemenata niza: ";
	cin >> n;

	int* niz = fibonaci(n);
	if (niz == nullptr)
	{
		cout << "Neispravan broj elemenata." << endl;
		return 0;
	}
	cout << "Fibonaci niz: ";
	for (int i = 0; i < n; i++)
	{
		cout << niz[i] << " ";
	}
	cout << endl;
	delete[] niz;
	return 0;
}