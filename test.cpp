#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

struct my_struct
{
  int a;
  int b;
};


class C 
{
public:
  C() { cout << "C constructor " << endl;}
  ~C() { cout << "C destructor " << endl;}
  //virtual void func() { cout << "func cal" << endl; }
};

class P : public C 
{
public:
  P() { cout << "P constructor " << endl;}
  ~P() { cout << "P destructor " << endl;}
  //void func() { cout << "child func" << endl; }
};

template <class T1, class T2> 
bool IsDerivedFrom(T1 &a, T2 &b)
{
  if ( std::is_base_of<T2, T1>::value )
    return true;
  else
    return false;
}

template <class T1, class T2>
bool IsTheSame(T1 &a, T2 &b)
{
  return false;
}

template <class T1>
bool IsTheSame(T1 &a, T1 &b)
{
  return true;
}

int main()
{
  cout << 25u - 50 << endl;
  cout << 25u + 50 << endl;
  cout << 25u - 50u << endl;
  
  my_struct a1 = {1, 2}; 
  my_struct *p = &a1;

  memset(p, 0, sizeof(*p));

  cout << p->a << endl << p->b << endl;
  
  C c1;
  P p1;  
  cout << IsDerivedFrom(p1, c1) << endl;

  cout << "c1 and p1 are the same : " << IsTheSame(c1, p1) << endl;
  cout << "c1 and c1 are the same : " << IsTheSame(c1, c1) << endl;
  return 0;
}
