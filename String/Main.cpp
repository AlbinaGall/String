#include <iostream>
using namespace std;

#define LENGHT 80

class String;

class String
{
	char str[LENGHT];
public:
	char get_str()const
	{
		for (int i = 0; i < LENGHT; i++) {
			return str[i];
		}
	}
	void set_str(const char* str)
	{
		for (int i = 0; i < LENGHT; i++) {
			this->str[i] = str[i];
		}
	}
	//             constructors:
	String()
	{
		for (int i = 0; i < LENGHT; i++) {
			this->str[i];
		}
		cout << "DefaultConstructor:\t" << this << endl;
	}
	String(const String& other)
	{
		for (int i = 0; i < LENGHT; i++) {
			this->str[i] = other.str[i];
		}
		cout << "CopyConstructor:\t" << this << endl;
	}
	~String()
	{
		cout << "Destructor:\t" << this << endl;
	}
	//				operators
	 String& operator=(const String& other)
	{
		for (int i = 0; i < LENGHT; i++) {
			this->str[i] = other.str[i];
			cout << "CopyAssignment:\t" << this;
		}
		cout << endl;
		return *this;
	}
	 void print() {
		 cout << "Print:\t";
		 for (int i = 0; i < LENGHT; i++) {			
			cout << this->str[i];
		}
		cout << endl;
	}
};

String& operator+( String& Left, String& Right)
{
	return Left + Right;
}

/*ostream& operator<<(ostream& os, const String& obj) {
	for (int i = 0; i < LENGHT; i++) {
		if (obj.get_str()) os << obj.get_str();
	}
	return os;
	
}

/*istream& operator>>(istream& is, String& obj) {
	if (obj.set_str()) is << obj.get_str();
	return is;	
}*/


void main() {
	setlocale(LC_ALL, "Russian");

	String str1;
	const char* s1 = "Hello ";
	str1.set_str(s1);
	//cout << str1 << endl;
	str1.print();
	

	String str2;
	const char* s2 = "World";
	str2.set_str(s2);
	//cout << str2 << endl;
	str2.print();

	String str3 = str1 + str2;
	//cout << str3 << endl;
	str3.print();

	String str4 = str1;
	//cout << str4 << endl;
	str4.print();
}