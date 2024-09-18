/**
 * 奇异递归模板模式
 * 继承者将自己作为模板参数传递给它的基类
 * 模板参数为类型则基类可以取到派生类的类型，从而实现类型转换
 * 同时，派生类，继承了基类，此时派生类是拥有基类的统一接口的
 */


#include <cstdio>


template <class Derived>
struct Base
{
  void name() { static_cast<Derived*>(this)->impl(); }
protected:
  Base() = default; // prohibits the creation of Base objects, which is UB
};

struct D1 : public Base<D1> { void impl() { std::puts("D1::impl()"); } };
struct D2 : public Base<D2> { void impl() { std::puts("D2::impl()"); } };
 
int main()
{
  D1 d1; d1.name();
  D2 d2; d2.name();
}