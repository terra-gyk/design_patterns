/**
 * 访问者模式是一种行为设计模式， 它能将算法与其所作用的对象隔离开来。
 * 访问者和实际对象是一对多的关系，访问者可以实现其中的某些方法，或者置空
 */

#include "visitor.h"

int main()
{
  auto component_1 = std::make_shared<component_a>();
  auto component_2 = std::make_shared<component_b>();
  auto visitor_1 = std::make_shared<visitor_a>();
  auto visitor_2 = std::make_shared<visitor_b>();
  component_1->accept(visitor_1);
  component_1->accept(visitor_2);
  component_2->accept(visitor_1);
  component_2->accept(visitor_2);
  return 0;
}