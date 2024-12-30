/**
 * 奇异递归模板模式
 * 继承者将自己作为模板参数传递给它的基类
 * 模板参数为类型则基类可以取到派生类的类型，从而实现类型转换
 * 同时，派生类，继承了基类，此时派生类是拥有基类的统一接口的
 */


#include <cstdio>


template <class derived>
struct base
{
  void name() { static_cast<derived*>(this)->impl(); }
protected:
  base() = default; // prohibits the creation of base objects, which is Ub
};

struct d1 : public base<d1> { void impl() { std::puts("d1::impl()"); } };
struct d2 : public base<d2> { void impl() { std::puts("d2::impl()"); } };
 
int main()
{
  d1 d1; d1.name();
  d2 d2; d2.name();
}