/**
 * 备忘录模式是一种行为设计模式， 允许在不暴露对象实现细节的情况下保存和恢复对象之前的状态。
 * 考虑编辑器的撤回模式
 * 备忘录模式将创建状态快照（Snapshot）的工作委派给实际状态的拥有者原发器（Originator）对象。
 * 这样其他对象就不再需要从“外部”复制编辑器状态了，编辑器类拥有其状态的完全访问权，因此可以自行生成快照。
 */

#include "memento.h"

int main()
{
  auto originator_1 = std::make_shared<originator>();
  auto caretaker_1 = std::make_shared<caretaker>(originator_1);
  caretaker_1->backup();
  originator_1->do_some();
  caretaker_1->backup();
  originator_1->do_some();
  caretaker_1->backup();
  originator_1->do_some();
  caretaker_1->backup();
  caretaker_1->show_history();

  caretaker_1->undo();
  caretaker_1->show_history();
  caretaker_1->undo();
  caretaker_1->show_history();
  return 0;
}