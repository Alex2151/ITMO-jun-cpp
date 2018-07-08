#ifndef DELEGATE_H
#define DELEGATE_H
#include <iostream>

void FunctionOne(int)  // type: void (*)(int)
{
  std::cout << "call FunctionOne \n";
}

void FunctionTwo(int)
{
  std::cout << "call FunctionTwo \n";
}

class Base
{
public:
  void MemberFunction(int)  // type: void (Base::*)(int)
  {
    std::cout << "call MemberFunction \n";
  }
};


struct Derived1 : public Base
{
    void MemberFunction(int)
    {
        std::cout << "Derived1 call MemberFunction \n";
    }
};

struct Derived2 : public Base
{
  virtual void MemberFunction(int);
};

struct MultipleInheritance : public Derived1, public Derived2
{
  virtual void MemberFunction(int);
};

struct VirtualMultipleInheritance : virtual public Derived1, virtual public Derived2
{
  virtual void MemberFunction(int);
};




class Delegate
{
  typedef void (*FreeFunction)(int);

public:
  void Bind(FreeFunction function)
  {
    m_function = function;
  }

  void Invoke(int ARG0)
  {
    (m_function)(ARG0);
  }

private:
  FreeFunction m_function;
};




class AbstractBase
{
public:
    virtual void CallFunction(int value) = 0;
};


template <typename T>
class MemberFunctionWrapper : public AbstractBase
{
    typedef void (T::*MemberFunction)(int);

public:
    MemberFunctionWrapper(MemberFunction mem_function)
    {
        member_function = mem_function;

    }

    virtual void CallFunction(int value)
    {
        (instance->*member_function)(value);
    }

private:
    T* instance;
    MemberFunction member_function;
};

void test()
{

//    Delegate delegate;
//    delegate.Bind(&FunctionOne);
//    delegate.Invoke(10);


//    delegate.Bind(&FunctionTwo);

//    delegate.Invoke(10);

//    Base c;
//    delegate.Bind(&Base::MemberFunction, &c);
//    delegate.Invoke(10);


    AbstractBase* function = new MemberFunctionWrapper<Derived1>(&Derived1::MemberFunction);

    function->CallFunction(10);


//    std::cout << "size: " << sizeof(&Base::MemberFunction) << std::endl;
//    std::cout << "size: " << sizeof(&Derived1::MemberFunction)<< std::endl;
//    std::cout << "size: " << sizeof(&Derived2::MemberFunction)<< std::endl;
//    std::cout << "size: " << sizeof(&MultipleInheritance::MemberFunction)<< std::endl;
//    std::cout << "size: " << sizeof(&VirtualMultipleInheritance::MemberFunction)<< std::endl;


}



#endif // DELEGATE_H
