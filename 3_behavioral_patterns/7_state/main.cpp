/**
 * 状态模式是一种行为设计模式， 让你能在一个对象的内部状态变化时改变其行为， 使其看上去就像改变了自身所属的类一样。
 * 状态模式是允许在handle中改变状态的，这里跟策略模式不一样
 */

#include "state.h"

int main()
{
  auto state_1 = std::make_shared<state_a>();
  auto state_2 = std::make_shared<state_b>();
  auto context_1 = std::make_shared<context>(state_1);
  context_1->request1();
  context_1->request2();
  // context_1->trans_state_to(state_2);
  context_1->request1();
  context_1->request2();
  return 0;
}