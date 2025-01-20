/**
 * 策略模式是一种行为设计模式， 它能让你定义一系列算法， 并将每种算法分别放入独立的类中， 以使算法的对象能够相互替换。
 * 状态可被视为策略的扩展。两者都基于组合机制：它们都通过将部分工作委派给“帮手”对象来改变其在不同情景下的行为。
 * 策略使得这些对象相互之间完全独立，它们不知道其他对象的存在。 但状态模式没有限制具体状态之间的依赖，且允许它们自行改变在不同情景下的状态。
 */

#include "strategy.h"

int main()
{
  std::string data = "fasdjf;l1i23lkja;lsdhjgasdf1231233sdb123";
  auto context_1 = std::make_shared<context>();
  auto strategy_1 = std::make_shared<strategy_a>();
  auto strategy_2 = std::make_shared<strategy_b>();
  context_1->do_some(data);

  context_1->set_strategy(strategy_1);
  context_1->do_some(data);
  context_1->set_strategy(strategy_2);
  context_1->do_some(data);

  return 0;
}