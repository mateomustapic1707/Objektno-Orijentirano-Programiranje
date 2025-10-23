#include <iostream>
#include <cstddef>
template <typename T>
inline bool ascending(T a, T b)
{
	return a > b;
}
template <typename T>
inline bool descending(T a, T b)
{
	return a < b;
}
template <typename T>

void sortt(T arr[], std::size_t n, bool(*cmp)(T, T))
{
	for (std::size_t i = 0; i < n - 1; i++)
	{
		for (std::size_t j = 0; j < n - i - 1; j++)
		{
			if (cmp(arr[j], arr[j + 1]))
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

int main() {
	int intArr[] = { 5, 2, 9, 1, 7 };
	double doubleArr[] = { 3.14, 1.41, 2.71, 0.57 };

	std::size_t n1 = sizeof(intArr) / sizeof(intArr[0]);
	std::size_t n2 = sizeof(doubleArr) / sizeof(doubleArr[0]);

	// Sortiranje int niza
	std::cout << "Originalni int niz: ";
	for (auto x : intArr) std::cout << x << " ";
	std::cout << "\n";

	sortt(intArr, n1, ascending);
	std::cout << "Int niz uzlazno: ";
	for (auto x : intArr) std::cout << x << " ";
	std::cout << "\n";

	sortt(intArr, n1, descending);
	std::cout << "Int niz silazno: ";
	for (auto x : intArr) std::cout << x << " ";
	std::cout << "\n\n";


	std::cout << "Originalni double niz: ";
	for (auto x : doubleArr) std::cout << x << " ";
	std::cout << "\n";

	sortt(doubleArr, n2, ascending);
	std::cout << "Double niz uzlazno: ";
	for (auto x : doubleArr) std::cout << x << " ";
	std::cout << "\n";

	sortt(doubleArr, n2, descending);
	std::cout << "Double niz silazno: ";
	for (auto x : doubleArr) std::cout << x << " ";
	std::cout << "\n";

	return 0;
}