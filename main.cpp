#include "string/string.h"

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
	const int count = 5;

	String lines[count]
	{
		"X01",
		"Z01",
		"Z11",
		"Y23",
		"Z34"
	};

	for (int i = 0; i < count; i++) {
		cout << lines[i] << endl;
	}
}