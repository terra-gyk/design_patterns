/**
 * 迭中介者模式是一种行为设计模式， 能让你减少对象之间混乱无序的依赖关系。 该模式会限制对象之间的直接交互， 迫使它们通过一个中介者对象进行合作。
 */

#include "mediator.h"


int main()
{
  auto component_a_1 = std::make_shared<component_a>();
  auto component_b_1 = std::make_shared<component_b>();
  auto mediator_1 = std::make_shared<sample_mediator>(component_a_1,component_b_1);
  component_a_1->set_mediator(mediator_1);
  component_b_1->set_mediator(mediator_1);
  component_a_1->do_some();
  component_b_1->do_some();

  return 0;
}