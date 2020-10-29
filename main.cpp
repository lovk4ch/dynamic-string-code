#include "string.h"

using namespace std;

istream& operator>>(istream& is, String& input)
{
	if (auto* array = input.GetArray()) {
		is >> array;
	}
	return is;
}

ostream& operator<<(ostream& os, String& output)
{
	if (auto* array = output.GetArray()) {
		os << array;
	}
	return os;
}

int main()
{
	cout << "Enter three lines" << endl;
	
	const int count = 3;
	String lines[count];

	for (int i = 0; i < count; i++) {
		cin >> lines[i];
	}

	for (int i = 0; i < count; i++) {
		cout << lines[i];
	}
}