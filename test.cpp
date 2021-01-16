#include "mystring.h"
#include <iostream>

#include<stdlib.h>


using std::cin;
using std::cout;
using std::endl;

int main() {

	MyString t1 = "hello";
	MyString t2 = t1;
	MyString t3(t2);
	cout << t1 <<  " " << t2 <<"  " << t2 << endl;
	t2 = "world";
	t1 = t1 + t2;
	t3 = t3 + "world";
	cout << t1 << "  " << t3 << endl;
	cin >> t3;
	for (char* i = t3.get_begin(); i != t3.get_end(); i++)cout << *i;
	cout << endl;
	cout << t3 << endl;
	cout << t1.cut(2, 4)<< endl;


}
