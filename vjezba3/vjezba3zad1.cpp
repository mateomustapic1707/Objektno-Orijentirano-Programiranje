#include <iostream>
#include <cstddef>

inline bool asceding(int a, int b)
{
	return a > b;
}
inline bool desceding(int a, int b)
{
	return a < b;
}

void sortt(int arr[], std::size_t n, bool(*cmp)(int, int))
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

int main()
{
	int arr[] = { 5,2,3,1,9 };
	std::size_t n = sizeof(arr) / sizeof(arr[0]);
	std::cout << "Orginalni niz: ";
	for (std::size_t i = 0; i < n; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << "\n";

	sortt(arr, n, asceding);
	std::cout << "Ulazno sortiranje: ";
	for (std::size_t i = 0; i < n; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << "\n";

	sortt(arr, n, desceding);
	std::cout << "Silazno sortiranje: ";
	for (std::size_t i = 0; i < n; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << "\n";

	return 0;
}