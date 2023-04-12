#include <iostream> 
using namespace std;

class D {
public:
	D() { cout << "D"; }
	virtual ~D() { cout << "~D"; }
};

class A : public D {
public:
	A() { cout << "A"; }
	~A() { cout << "~A"; }
};

class C : public D {
public:
	C() { cout << "C"; }
	~C() { cout << "~C"; }
};

class B : public A, C {
public:
	B() { cout << "B"; }
	~B() { cout << "~B"; }
};

int main() {
	A *b = new B();
	delete b;
	int a;
	cin >> a;
	return 0;
}