#include <iostream> 
using namespace std; 

class D { 
public: 
  D () { cout << "D"; } 
  ~D () { cout << "~D"; } 
}; 

class A : virtual public D{ 
public: 
  A () { cout << "A";} 
  virtual ~A() { cout << "~A";} 
}; 

class C : virtual public D{ 
public: 
  C () { cout << "C";} 
  ~C () { cout << "~C";}  
}; 

class B : public A, C { 
public: 
  B () {cout << "B";} 
  virtual ~B () { cout << "~B"; } 
}; 

int main () { 
  A *b = new B (); 
  delete b;

  int a;
  cin >> a;

  return 0; 
} 