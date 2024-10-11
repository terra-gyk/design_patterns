/**
 * 
当我们使用工厂(factory)这个词的时候，我们通常指下面两种情况中的一种：
- 一个知道如何创建对象的类
- 一个被调用时会创建对象的函数

涉及到的术语：
- 工厂方法（factory method）是类的成员函数，可以作为创建对象的一种方式，通常用来替代构造函数。
- 工厂（factory）通常是知道如何创建对象的独立的类，尽管如果你传递构造对象的函数(std::function，函数指针或者函数对象)到某个函数里面，这个参数通常也被称为工厂。
- 抽象工厂（abstract factory），顾名思义，是一个抽象类，可以被生产一系列对象的具体类所继承。抽象工厂在实际中很少见。

工厂相对于构造函数调用有下面几个关键的优势：
- 工厂可以说“不”，这意味着除了选择返回一个对象外，它可以返回一个空指针(nullptr)。
- 命名更有直观意义，且不受限，不像构造函数的函数名必须和类名相同。
- 一个工厂能够生产出许多不同类型的对象。
- 工厂能够表现出多态行为，实例化一个类并通过基类的引用或指针返回实例化后的对象。
- 工厂能够实现缓存(caching)和其他存储优化，他也是其他方法，例如池或单例模式，实现的自然的选择。

工厂与建造者模式的不同之处在于，对于工厂，您通常一次性创建一个对象，而对于建造者，您通过部分地提供信息来分段地构造对象。
 
*/

#include "product.h"
#include "factory.h"
#include "abstract_factory.h"

#include <iostream>

int main()
{
  creator creator;
  auto product_a = creator.create_product_a();
  std::cout << product_a->get_name() << std::endl;

  auto product_b = creator.create_product_b();
  std::cout << product_b->get_name() << std::endl;

  auto product_a_1 = creator.create_product(product_type::A);
  std::cout << product_a_1->get_name() << std::endl;

  auto product_b_1 = creator.create_product(product_type::B);
  std::cout << product_b_1->get_name() << std::endl;

  auto product_c_1 = creator.create_product_c_by_age(25);
  std::cout << product_c_1->get_name() << std::endl;

  auto product_c_2 = creator.create_product_c_by_name("terra");
  std::cout << product_c_1->get_name() << std::endl;

  auto factory = std::make_unique<drink_factory>();
  auto drink_tea = factory->make_drink("tea");
  auto drink_coffee = factory->make_drink("coffee");

  return 0;
}