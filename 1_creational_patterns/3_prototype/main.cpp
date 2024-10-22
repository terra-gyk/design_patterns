/**
 * 原型设计模式阐释了对象深度拷贝的概念，并不需要每次都通过构造函数完整初始化来创建一个对象，可以对创建好的对象进行复制，复制产生的对象和原来的对象互不依赖，稍加修改后就能得到想要的新对象。
 * 在C++中实现原型模式实际上只存在两种方法，且都需要手动实现：
 * - 在代码中正确的复制对象，即进行深拷贝。可以在拷贝构造函数/拷贝赋值运算符或单独的成员函数中实现。
 * - 在代码中支持序列化/反序列化，序列化后再进行反序列化实现拷贝。该方法需要额外的计算开销，拷贝频率越高，开销越大。该方法相对于拷贝构造函数的唯一优点是能复用已有的序列化代码。
 */

#include "prototype.h"

#include <iostream>

int main()
{
  auto client_t = std::make_unique<client>();
  client_t->init();

  auto type_a = client_t->get_prototype("a");
  std::cout << type_a->type() << std::endl;
  
  auto type_b = client_t->get_prototype("b");
  std::cout << type_b->type() << std::endl;
  return 0;
};