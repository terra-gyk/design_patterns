/**
 * 观察者模式是一种行为设计模式，允许你定义一种订阅机制，可在对象事件发生时通知多个“观察”该对象的其他对象。
 * 拥有一些值得关注的状态的对象通常被称为目标，由于它要将自身的状态改变通知给其他对象，我们也将其称为发布者（publisher）。所有希望关注发布者状态变化的其他对象被称为订阅者（subscribers）。
 */

#include "observer.h"

int main()
{
  auto subject_1 = std::make_shared<subject>();
  subject_1->do_some();
  auto observer_1 = std::make_shared<observer>();
  subject_1->add_observer(observer_1);
  subject_1->add_observer(observer_1);
  auto observer_2 = std::make_shared<observer>();
  auto observer_3 = std::make_shared<observer>();
  auto observer_4 = std::make_shared<observer>();
  auto observer_5 = std::make_shared<observer>();
  subject_1->add_observer(observer_2);
  subject_1->add_observer(observer_3);
  subject_1->add_observer(observer_4);
  subject_1->add_observer(observer_5);
  subject_1->do_some();

  return 0;
}