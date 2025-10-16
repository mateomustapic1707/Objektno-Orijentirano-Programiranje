#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	bool flag;
	cout << "Unesi logicku vrijednost (0 ili 1): ";
	cin >> flag;
	cout << boolalpha << "boolalpha: " << flag << endl;

	int a = 152;
	cout << "\nBroj u razlicitim bazama:" << endl;
	cout << "dec: " << dec << a << endl;
	cout << "hex: " << showbase << hex << uppercase << a << endl;
	cout << "oct: " << oct << a << endl;

	double pi = 3.141592;
	cout << "\nPi u razlicitim formatima:" << endl;
	cout << fixed << setprecision(3) << "fixed: " << pi << endl;
	cout << scientific << setprecision(2) << uppercase << "scientific: " << pi << endl;

	cout << "\nPoravnavanje i ispunjavanje:" << endl;
	cout << setw(14) << setfill('-') << right << 42 << endl;
	return 0;
}
