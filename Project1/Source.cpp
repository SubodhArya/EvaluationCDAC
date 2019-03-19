#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<string.h>
class myString  //user defined string class with char* and int as members holding character array and length of the array
{

	char *name;
	int length;

public:

	myString() //default constructor
	{
		name = NULL;
		length = 0;
	}

	myString(const char *s) //parameterised constructor passing char* value
	{
		name = new char[strlen(s) + 1];
		strcpy(name, s);
		length = strlen(s);
	}

	myString(const myString &s) //copy constructor
	{

		name = new char[s.length + 1];
		strcpy(name, s.name);
		length = s.length;
	}

	void print_String()
	{
		cout << endl << name;
	}
	void scan_String()
	{
		name = new char[10];
		cin >> name;
	}



	myString operator=(myString c) //overloading = operator as a member function
	{
		delete[] name;
		name = new char[strlen(c.name) + 1];
		strcpy(name, c.name);
		length = c.length;
		return (*this);
	}


	myString operator+(myString &c) //overloading + operator for concat
	{

		myString temp;
		temp.length = length + c.length;
		temp.name = new char[temp.length + 1];
		strcpy(temp.name, name);
		//	cout<<endl;
		//	cout<<temp.string_ptr;

		strcat(temp.name, c.name);
		//	cout<<temp.string_ptr;
		return temp.name;
	}
	friend ostream& operator<<(ostream &cout, const myString &c);
	friend istream& operator>>(istream &cin, myString &c);
	friend void sort(myString names[], int size);
	~myString() {
		delete[] name;
		name = NULL;
		cout << endl << "deleted object";
	}
};

void sort(myString names[], int size) {//takes array of mtString objects and bubble sorts them
	//Performing bubble sort

	for (int i = 0;i < size - 1;i++) {
		for (int j = 0;j < size - i - 1;j++) {
			if (strcmp(names[j].name, names[j + 1].name) > 0) {
				myString temp;
				temp = names[j];
				names[j] = names[j + 1];
				names[j + 1] = temp;
			}
		}
	}
}
ostream& operator<<(ostream &cout, const myString &c)
{
	cout << c.name;
	return cout;
}
istream& operator>>(istream &cin, myString &c)
{
	char buffer[100];
	cin >> buffer;
	c.name = new char[strlen(buffer) + 1];
	c.length = strlen(buffer);
	strcpy(c.name, buffer);
	//cin>>c.string_ptr;
	return cin;
}
int main()
{
	myString def_str, para_str("Hello"), copy_str(para_str), deep_str, concat_str;
	//using normal member functions to scan the input 
	cout << "Enter the string for showing input member function:";
	def_str.scan_String();
	cout << "Entered string is :";
	cout << def_str;
	//demonstrating parametarised constructor result
	cout << endl << "Parameterised constructer string contains :";
	para_str.print_String();
	//demonstarting copy constructor result
	cout << endl << "copy constructor string has :";
	copy_str.print_String();
	deep_str = def_str;  //deep copying by overloading '=' operator
	cout << endl << "deep copied string has :";
	deep_str.print_String();
	//overloading '+' operator now to concat strings
	cout << endl << "concatinating copystr:" << copy_str << " and " << deep_str;
	concat_str = copy_str + deep_str;
	cout << endl << "After concatinating result is concat_str :";
	cout << concat_str << endl;
	//Lets perform sort
	cout << "Performing bubble sort" << endl;
	cout << "enter the no of names you require" << endl;
	int namesize;
	cin >> namesize;
	myString *names = new myString[namesize];
	for (int i = 0;i < namesize;i++) {
		cin >> names[i];
	}
	cout << "the initial array details are" << endl;
	for (int i = 0;i < namesize;i++) {
		cout << names[i] << endl;
	}
	sort(names, namesize);
	cout << "After sorting array details are" << endl;
	for (int i = 0;i < namesize;i++) {
		cout << names[i] << endl;
	}
	system("pause");

	return 0;
}


