#include <iostream>
using namespace std;

class A
{
public:
  A()
  {
    cout << "A()\n";
  }
  virtual ~A()
  {
    cout << "~A()\n";
  }

  void f()
  {
    cout << "A::f\n";
  }
};

class B : virtual public A
{
public:
  B()
  {
    cout << "B()\n";
  }
  virtual ~B()
  {
    cout << "~B()\n";
  }

  void f()
  {
    cout << "B::f\n";
  }
};

class C : public B
{
public:
  C()
  {
    cout << "C()\n";
  }
  virtual ~C()
  {
    cout << "~C()\n";
  }
};

class D : public C,  virtual public A
{
public:
  D()
  {
    cout << "D()\n";
  }
  virtual ~D()
  {
    cout << "~D()\n";
  }
};


int main(int argc, char *argv[])
{
  B *p = new D;
  p->f();

  delete p;
  return 0;
}