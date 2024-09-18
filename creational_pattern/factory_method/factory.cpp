#include <cstdio>
 
template <class Derived>
struct Base
{
  void name() 
  { 
    (static_cast<Derived*>(this))->impl(); 
  }
protected:
  Base() = default; // 禁止创建 Base 对象，这是 UB
};

struct D1 : public Base<D1> 
{
  void impl() { std::puts("D1::impl()"); } 
};

struct D2 : public Base<D2> 
{ 
  void impl() { std::puts("D2::impl()"); } 
};

int main()
{
  D1 d1; d1.name();
  D2 d2; d2.name();
}