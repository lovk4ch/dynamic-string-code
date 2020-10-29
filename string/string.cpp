#include "string.h"

using namespace std;

String::String()
{
	this->Size = 0;
	this->arr = nullptr;
}

String::~String()
{
	delete[] this->arr;
}

String::String(const char* arr)
{
	this->Size = strlen(arr);
	this->arr = new char[this->Size + 1];

	for (int i = 0; i < this->Size; i++) {
		this->arr[i] = arr[i];
	}
	this->arr[this->Size] = '\0';
}

String::String(const String &other)
{
	SetArray(other.arr);
}

char* String::GetArray()
{
	return this->arr;
}

void String::SetArray(char* arr)
{
	this->Size = strlen(arr);
	this->arr = new char[this->Size + 1];

	for (int i = 0; i < this->Size; i++) {
		this->arr[i] = arr[i];
	}
	this->arr[this->Size] = '\0';
}

String String::operator+(const String& other)
{
	int Size = this->Size + other.Size + 1;
	String concat(new char[Size]);

	int i;
	for (i = 0; i < this->Size; i++) {
		concat.arr[i] = this->arr[i];
	}
	int j;
	for (j = 0; i < Size - 1; i++, j++) {
		concat.arr[i] = other.arr[j];
	}
	concat.arr[Size - 1] = '\0';
	return concat;
}

String& String::operator=(const String &other)
{
	if (this->arr != nullptr) {
		delete[] this->arr;
	}

	SetArray(other.arr);
	return *this;
}