#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <iostream>
#include <assert.h>

using namespace std;
namespace mbf
{
	class string
	{
	private:
		char* _str;
		size_t _size;
		size_t _capacity;
	public:
		typedef char* iterator;

		iterator begin()
		{
			return _str;
		}
		iterator end()
		{
			return _str+_size;

		}
		string(const char* str = "")
		{
			_size = strlen(str);
			_capacity = _size;
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}
		char& operator[](size_t i)
		{
			assert(i < _size);
			return _str[i];
		}
		~string()
		{
			delete[] _str;
			_str = nullptr;
			_size = _capacity = 0;
		}
	};
}
