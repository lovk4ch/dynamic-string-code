#include <iostream>

class String
{
public:
	// constructors / destructors
	String();
	~String();
	String(const char* arr);
	String(const String& other);

	// props
	int Size;

	// methods
	char* GetArray();
	void SetArray(char* arr);

	// operators
	String operator+(const String& other);
	String& operator=(const String& other);

private:
	char* arr;
};

/*istream& operator>>(istream& is, String& input)
{
	is >> input.GetArray();
	return is;
}*/