#include <iostream>
using namespace std;

class Rectangle {
public:
	int* a;
	int* b;
	Rectangle() {
		cout << "Default constructor" << endl;
		this->a = new int();
		this->b = new int();
	}

	Rectangle(int a, int b) {
		cout << "With Parametr constructor" << endl;
		this->a = new int(a);
		this->b = new int(b);
	}

	Rectangle(const Rectangle& other) {
		cout << "Copy constructor" << endl;
		this->a = new int(*other.a);
		this->b = new int(*other.b);
	}

	Rectangle& operator=(const Rectangle& other) {
		cout << "Copy assign operator" << endl;
		*this->a = *other.a;
		*this->b = *other.b;
		return *this;
	}

	Rectangle& operator+=(const Rectangle& other) {
		*this->a += *other.a;
		*this->b += *other.b;
		return *this;
	}

	Rectangle& operator*=(const Rectangle& other) {
		*this->a *= *other.a;
		*this->b *= *other.b;
		return *this;
	}

	Rectangle& operator/=(const Rectangle& other) {
		if (*other.b != 0 && *other.a != 0) {
			*this->a /= *other.a;
			*this->b /= *other.b;
		}
		return *this;
	}

	//Rectangle& operator-= (const Rectangle & other) {
	//	*this->a -= *other.a;
	//	*this->b -= *other.b;
	//}

	Rectangle operator+(const Rectangle& other) {
		Rectangle temp;
		*temp.a = *other.a + *this->a;
		*temp.b = *other.b + *this->a;
		return temp;
	}
	~Rectangle() {
		cout << "Destructor "<<*this->a << endl;
		delete a;
		delete b;
	}
};

void main() {
	/*Rectangle r1;
	Rectangle r2(3, 4);*/
	//Rectangle r3 = r2;
	//*r2.a = 100;
	//cout << *r1.a << endl;
	//cout << *r2.a << endl;
	//cout << *r3.a << endl;
	//Rectangle r3(6,8);
	//r3 = r2; // copy assign operator
	Rectangle r1(12, 13);
	Rectangle r2(5, 10);
	cout << *r1.a << endl;
	cout << *r1.b << endl;
	r1 += r2;
	cout << *r1.a << endl;
	cout << *r1.b << endl;
}