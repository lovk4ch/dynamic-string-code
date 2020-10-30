#include "sorting/sorting.h"
#include <ctime>

using namespace std;

int main()
{
	const int count = 5;
	const char* arr[count]
	{
		"A0001",
		"C01",
		"B23",
		"C133",
		"C1311",
	};

	cout << "Sorting through custom String: " << endl;
	Sort(count, arr);

	cout << "Sorting through vector String: " << endl;
	SortSTL(count, arr);
}