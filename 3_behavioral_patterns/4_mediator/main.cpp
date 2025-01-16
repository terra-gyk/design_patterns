/**
 * 迭中介者模式是一种行为设计模式， 能让你减少对象之间混乱无序的依赖关系。 该模式会限制对象之间的直接交互， 迫使它们通过一个中介者对象进行合作。
 * 类之间如果有较多的交互，而如果直接引用类，一个是类内成员会很混乱，一个是不好管理，不如把这部分对象统一管理起来，如果类质检需要交互，通过管理者来进行通知。
 * 缺点，这个中介者，如果互相依赖的类变多，可能会演变成一个上帝类。
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