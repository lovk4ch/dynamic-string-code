#include <iostream>

class String
{
	public:
		// constructors / destructors
		String();
		~String();
		String(const char* arr);
		String(const String& other);
		String(String&& other) noexcept;

		// methods
		size_t GetSize();
		char* GetArray();
		void SetArray(const char* arr);

		// operators
		char& operator[](size_t index);
		bool operator>(const String& other);
		bool operator<(const String& other);
		String operator+(const String& other);
		String& operator=(const String& other);

	private:
		char* m_arr;
		size_t m_size;
};