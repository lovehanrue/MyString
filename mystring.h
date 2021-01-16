#pragma once
#include<iostream>

using std::ostream;
using std::istream;
class MyString {
public:
	MyString();
	MyString(const char* str);
	MyString(const MyString& str);
	~MyString();
	int get_size() const;
	char* get_begin() const;
	char* get_end() const;

	char operator[](int i) const;
	MyString& cut(int begin, int end);
    MyString& operator=(const MyString& other);
	MyString& operator=(const char* str);
	MyString& operator+(const MyString& other);
	MyString& operator+(const char* str);
	friend ostream& operator<< (ostream& out, MyString& mystr);
	friend istream& operator>> (istream& in, MyString& mystr);


private:
	int m_size;
	char* m_str;
};