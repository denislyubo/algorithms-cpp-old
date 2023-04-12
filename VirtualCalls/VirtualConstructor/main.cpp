class A
{
 void f(){}

};
class B : A
{
 
  B()
  {

  }



};

void foo(A&a) {}

int main(int argc, char* argv[])
{
  B b;
  //foo(b);
  return 0;
}