#include <iostream>

using namespace std;
class A {
public:
	A() {
		cout << "A()" << endl;
	}

	A(const A& rhs)	{
		cout << "A(const A& rhs)" << endl;
	}

	/*A&*/void operator=(const A& rhs) {
		cout << "A& operator=(const A& rhs)" << endl;
		//return A();
	}

	A(A&& rhs) {
		cout << "A(A&& rhs)" << endl;
	}


	void operator=(const A&& rhs) {
		cout << "void operator=(const A&& rhs)" << endl;
		//return A();
	}

	//A(A&& rhs) = delete;

};

A func()
{
	cout << "func()" << endl;

	A a;

	return a;
}

A func1(A a)
{
	cout << "func1()" << endl;

	return a;
}


int main()
{
	A a;
	a = func1(a);
	//A a1(func());

	char b;
	cin >> b;

	return 0;
}