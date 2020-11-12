#include "string.h"

using namespace std;

String::String()
{
	m_size = 0;
	m_arr = nullptr;
}

String::~String()
{
	delete[] m_arr;
}

String::String(const char* arr)
{
	SetArray(arr);
}

String::String(const String &other)
{
	SetArray(other.m_arr);
}

String::String(String&& other) noexcept
{
	m_size = other.m_size;
	m_arr = other.m_arr;
	other.m_arr = nullptr;
}

size_t String::GetSize()
{
	return m_size;
}

char* String::GetArray()
{
	return m_arr;
}

/// <summary>
/// Set char buffer
/// </summary>
/// <param name="arr">null terminated string</param>
void String::SetArray(const char* arr)
{
	if (!m_arr) {
		delete[] m_arr;
	}

	m_size = strlen(arr) + 1;
	m_arr = new char[m_size];
	strcpy_s(m_arr, m_size, arr);
}

char& String::operator[](size_t index)
{
	if (index < m_size)
		return m_arr[index];

	return m_arr[0];
}

bool String::operator>(const String& other)
{
	size_t size = m_size < other.m_size ? m_size : other.m_size;

	for (int i = 0; i != size; ++i) {
		if (m_arr[i] != other.m_arr[i]) {
			return m_arr[i] > other.m_arr[i];
		}
	}
	return true;
}

bool String::operator<(const String& other)
{
	return !operator>(other);
}

String String::operator+(const String& other)
{
	int size = m_size + other.m_size + 1;
	String concat(new char[size]);

	strcpy_s(concat.m_arr, m_size, m_arr);
	strcpy_s(concat.m_arr + m_size - 1, other.m_size + 1, other.m_arr);

	return concat;
}

String& String::operator=(const String &other)
{
	if (m_arr) {
		delete[] m_arr;
	}

	SetArray(other.m_arr);
	return *this;
}