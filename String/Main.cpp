#include <iostream>
using namespace std;

//#define LENGHT 80

class String;
String operator+(const String& left, const String& right);

class String
{
	//char str[LENGHT];
	unsigned int size;
	char* str;
public:
	/*char get_str()const
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
	}*/
	//             constructors:
	/*String()
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
	}*/
	unsigned int get_size() const {
		return size;
	}
	const char* get_str()const {
		return str;
	}
	char* get_str(){
		return str;
	}
	explicit String(unsigned int size = 80) {
		this->size = size;
		this->str = new char[size] {};
		cout << "DefaultConstructor: " << this << endl;
	}
	String(const char* str) {//константный указатель на char - это строковая костанта
		//while (str[size++]);
		this->size = strlen(str) + 1; //+1 потому что size хранит размер в байтах,а strlen() считает размер в символах
		this->str = new char[size] {};
		for (int i = 0; i < size; i++) this->str[i] = str[i];
		cout << "OneArgConstructor: " << this << endl;
	}
	String(const String& other)
	{
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++) 	this->str[i] = other.str[i];
		cout << "CopyConstructor:\t" << this << endl;
	}
	~String() {
		delete[] this->str;//[] - показывает, что нужно удалить массив
		cout << "Destructor: " << this << endl;
	}
	//     methods
	void print() const {
		cout << "Size: " << size << endl;
		cout << "String: " << str << endl;
	}
	//     operators
	String& operator=(const String& other)
	{
		//0) проверяем не является ли принятый объект нашим объектом
		if (this == &other) return *this;
		//1) удаляем старое значение об-та,т.е. освобождаем занимаемую им память
		delete[] this->str;
		//2) выполняем deep copy
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++) 	this->str[i] = other.str[i];
		cout << "CopyAssignment:\t" << this << endl;
		return *this;
	}
	String& operator+=(const String& other) {
		return *this = *this + other;
	}
	//Оператор [] (оператор индексирования - Subscript operator) возвращает значение по индексу
	const char& operator[](unsigned int i) const{//i - индекс
		return str[i];
	}
	char& operator[](unsigned int i) {
		return str[i];
	}
};

ostream& operator<<(ostream& os, const String& obj) {
	return os << obj.get_str();
}
String operator+(const String& left, const String& right)
{
	//создаем строку, в которую поместим результат и вычисляем ее размер
	String cat(left.get_size() + right.get_size() - 1);
	for (int i = 0; i < left.get_size(); i++) 
		cat[i] = left[i];
		//cat.get_str()[i] = left.get_str()[i];
	for (int i = 0; i < right.get_size(); i++)
		cat[i+left.get_size()-1] = right[i];
		//cat.get_str()[i+left.get_size()-1] = right.get_str()[i];
	return cat;
}
	
/*String& operator+( String& Left, String& Right)
{
	return Left + Right;
}*/

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
//#define CONSTRUCTORS_CHECK
void main() 
{
	setlocale(LC_ALL, "russian");

#ifdef CONSTRUCTORS_CHECK
	//String str = 5; //Implicit conversion
	String str(5);//Explicit constructor можно вызвать только так и нельзя вызвать оператором =
	str.print();

	String str1 = "Hello";
	str1 = str1;
	str1.print();

	String str2 = str1;
	str2.print();

	String str3;
	str3 = str2;
	str3.print();
#endif //CONSTRUCTORS_CHECK

	String str1 = "Hello";
	cout << str1 << endl;
	String str2 = "World";
	cout << str2 << endl;
	String str3 = str1 + ", " + str2 + "!";
	cout << str3 << endl;

	str1 += str2;
	cout << str1 << endl;
	/*String str1;
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
	str4.print();*/

	
}