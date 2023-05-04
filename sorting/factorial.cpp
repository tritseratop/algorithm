#include <iostream>
#include <algorithm>

int recursiveFactorial(int n) {
  if (n == 1) return 1;
  return n + recursiveFactorial(n - 1);
}

int cycleFactorial(int n) {
  int result = 0;
  while (n >= 1) {
    result += n;
    --n;
  }
  return result;
}

//class Base {
//public:
//    virtual ~Base() {}
//
//    virtual void out() {
//        std::cout << "Base" << std::endl;
//    }
//};
//
//class Derived : private Base {
//public:
//    Derived() = default;
//
//private:
//    void out() {
//        std::cout << "Derived" << std::endl;
//    }
//};

class A {
public: 
    void foo() {
        std::cout << "This is base!" << std::endl;
    }
};

class First : public A {};
class Second : public A {};

class Third : public First, public Second {};

class Base
{
public:
    Base() { init(); }
    ~Base() {}

    virtual void log() = 0;

private:
    void init() { log(); }
};

class Derived : public Base
{
public:
    Derived() {}
    ~Derived() {}

    virtual void log() { std::cout << "Derived created" << std::endl; }
};

using namespace std;

int main()
{
    Third* a = new Third();
    dynamic_cast<First*>(a)->foo();
    Derived d;
    //Base* ptr = new Derived();
    /*std::shared_ptr<Base> sharedptr = std::reinterpret_pointer_cast<Base>(std::make_shared<Derived>());
    sharedptr->out();*/
    //cout << recursiveFactorial(12);

  return 0;
}
