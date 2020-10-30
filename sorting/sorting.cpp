#include "../sorting/sorting.h"

using namespace std;

ostream& operator<<(ostream& os, String& output)
{
	if (auto* array = output.GetArray()) {
		os << array;
	}
	return os;
}

int comp(const void* a, const void* b)
{
	return (*(String*)a < *(String*)b);
}

void Sort(const int count, const char *arr[])
{
	vector<String> vector;

	for (int i = 0; i != count; ++i) {
		vector.push_back(String(arr[i]));
	}

	sort(vector.begin(), vector.end());
	reverse(vector.begin(), vector.end());

	for (int i = 0; i < count; i++) {
		cout << vector[i] << endl;
	}
	cout << endl;
}

void SortSTL(const int count, const char* arr[])
{
	vector<string> vector;

	for (int i = 0; i != count; ++i) {
		vector.push_back(arr[i]);
	}

	sort(vector.begin(), vector.end());
	reverse(vector.begin(), vector.end());

	for (int i = 0; i < count; i++) {
		cout << vector[i] << endl;
	}
	cout << endl;
}