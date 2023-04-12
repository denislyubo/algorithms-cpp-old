#include <iostream>

using namespace std;

class MyExeption
{
public:
	MyExeption() { cout << "MyExeption "; }
	~MyExeption() { cout << "~MyExeption "; }
	void message() { cout << "MyExeptoin::message "; }
};

class A
{
public:
	A() { cout << "A() "; }
	~A() { cout << "~A() "; }
};

class B
{
public:
	B() { cout << "B() "; }
	~B() { cout << "~B() "; }
};

class C
{
public:
	C() 
	{ 
		cout << "C() ";
		throw MyExeption();
	}
	~C() { cout << "~C() "; }
};

int main()
{
	A a;
	B b;
	try
	{
		C c;
	}
	catch (MyExeption& exptionObj)
	{
		exptionObj.message();
		return 0;
	}
	catch (...)
	{
		return 0;
	}
}