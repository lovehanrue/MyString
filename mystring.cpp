#include<iostream>
#include "mystring.h"

const int index_value = 100;

using std::ostream;
using std::cout;
using std::endl;
using std::istream;

MyString::MyString() {
	m_size = 0;
	m_str = nullptr;
}

MyString::MyString(const char* str) {
	int len = -1;
	while (str[++len] != '\0');
	m_size = len;
	m_str = new char[m_size + 1];
	for (int i = 0; i < m_size; i++) {
		m_str[i] = str[i];
	}
}

MyString::MyString(const MyString& other) {
	m_size = other.get_size();
	m_str = new char[m_size + 1];
	for (int i = 0; i < m_size; i++) {
		m_str[i] = other[i];
	};

}

MyString:: ~MyString() {
	if (m_str != nullptr) {
		delete[] m_str;
		m_str = nullptr;
	}
	m_size = 0;
}

int MyString::get_size() const {
	return m_size;
}

char* MyString::get_begin() const {
	return m_str;
}

char* MyString::get_end() const {
	return m_str + m_size;
}

MyString& MyString::cut(int begin, int end) {
	char* str = new char[end - begin];
	for (int i = begin; i <= end ; i++) {
		str[i - begin] = m_str[i - 1];
	}
	//cout << str << endl;
	return *(new MyString(str));
}

char MyString::operator[](int i) const {
	if (i >= 0 && i < m_size) {
		return m_str[i];
	}
	else {
		return ' ';
	}
}

MyString& MyString::operator= (const MyString& other) {
	if (&other == this) return *this;
	if (m_str != nullptr) {
		delete[] m_str;
		m_str = nullptr;
	}
	m_size = other.get_size();
	m_str = new char[m_size + 1];
	for (int i = 0; i < m_size; i++) {
		m_str[i] = other[i];
	};


	return *this;

}

MyString& MyString::operator= (const char* str) {
	m_size = 0;
	while (str[m_size++] != '\0');
	//cout << sizeof(str) << std::endl;
	if (m_str != nullptr) {
		delete[] m_str;
	}
	m_str = new char[m_size];
	for (int i = 0; i < m_size; i++) {
		m_str[i] = str[i];
	}
	m_size -= 1;
	//cout << m_str << std::endl;
	//cout << m_size << std::endl;
	return *this;
}

MyString& MyString::operator+ (const MyString& other) {
	if (m_str == nullptr) {
		return *(new MyString(other));
	}
	int size = other.get_size() + m_size;
	char* temp_str = new char[size + 1];
	for (int i = 0; i < m_size; i++) {
		temp_str[i] = m_str[i];
	}
	for (int i = m_size; i < size; i++) {
		temp_str[i] = other[i - m_size];
	}
	delete[] m_str;
	m_str = temp_str;
	m_size = size;
	//cout << m_str << std::endl;
//	cout << m_size << std::endl;


	return *this;

}

MyString& MyString::operator+(const char* str) {
	int size = 0;
	while (str[size] != '\0') size++;
	char* temp_str = new char[m_size + size];
	for (int i = 0; i < m_size; i++) {
		temp_str[i] = m_str[i];
	}

	for (int i = m_size; i < m_size + size; i++) {
		temp_str[i] = str[i - m_size];
	}
	delete[]  m_str;
	m_str = temp_str;
    m_size += size;
	//cout << m_str << std::endl;
	
	return *this;


}

ostream& operator<<(ostream& out, MyString& mystr) {
	for (int i = 0; i < mystr.m_size; i++) {
		out << mystr[i];
	}

	return out;
}

istream& operator>>(istream& in, MyString& mystr) {
	char str[index_value];
	in >> str;
	mystr.m_size = 0;
	while (str[mystr.m_size++] != '\0');
	if (mystr.m_str != nullptr) {
		delete[] mystr.m_str;
	}
	mystr.m_str = new char[mystr.m_size + 1];
	for (int i = 0; i < mystr.m_size; i++) {
		mystr.m_str[i] = str[i];
	}
	
	return in;
}
