#include <iostream>
using namespace std;

int ogranicenje(int x, int low = 0, int high = 100)
{
	if (x < low)
	{
		return low;
	}
	else if (x > high)
	{
		return high;
	}
	else
		return x;
}

double ogranicenje(double x, double low = 0.0, double high = 100.0)
{
	if (x < low)
	{
		return low;
	}
	else if (x > high)
	{
		return high;
	}
	else
		return x;
}

int main()
{
	int i;
	double d;

	cout << "Unesi cijeli broj: ";
	cin >> i;
	cout << "Ograniceni broj: " << ogranicenje(i) << endl;

	cout << "Unesi realni broj: ";
	cin >> d;
	cout << "Ograniceni broj: " << ogranicenje(d) << endl;

	return 0;
}

