/**
 * 命令模式是一种行为设计模式， 它可将请求转换为一个包含与请求相关的所有信息的独立对象。 该转换让你能根据不同的请求将方法参数化、 延迟请求执行或将其放入队列中， 且能实现可撤销操作。
 * 命令模式包含以下几个角色：
 *   命令（Command）：定义了一个操作的接口，包括执行操作的方法和撤销操作的方法。
 *   具体命令（ConcreteCommand）：实现了命令接口，包含了具体的操作和接受者。
 *   接受者（Receiver）：执行命令所要进行的操作，知道如何实现具体的请求。
 *   调用者（Invoker）：负责调用命令对象执行请求，通常会持有命令对象的实例(可以有多个命令)。
 *   客户端（Client）：创建具体的命令对象并设置其接收者，命令对象的生命周期由客户端管理。
 * 如果你需要通过操作来参数化对象，可使用命令模式。
 * 如果你想要将操作放入队列中、操作的执行或者远程执行操作，可使用命令模式。
 * 如果你想要实现操作回滚功能，可使用命令模式。
 */

#include "command.h"


int main()
{
  auto invoke_1 = invoke{};
  auto receiver_a_1 = std::make_shared<receiver_a>();
  auto receiver_b_1 = std::make_shared<receiver_b>();

  auto command_a_1 = std::make_shared<command_a>(receiver_a_1,"some things 1");
  auto command_b_1 = std::make_shared<command_b>(receiver_b_1,"some things 2");

  invoke_1.add_command(command_a_1);
  invoke_1.add_command(command_b_1);

  invoke_1.execute_command();

  return 0;
}