/**
 * 适配器模式：我们想要的接口和现有的接口不同时，我们可以在现有的接口上构造一个适配器来支持想要的接口。
 */

#include "adapter.h"

#include <memory>

int main()
{
  std::shared_ptr<target> my_target(new target);
  std::shared_ptr<target> my_adapter(new adapter);
  std::shared_ptr<adaptee> my_adaptee(new adaptee);
  client::client_code(my_target);
  std::cout << my_adaptee->reverse_request() << std::endl;
  client::client_code(my_adapter);
  
  tools_a a;
  // tools_b b;
  tools_adapter tools_adapter(a);
  tools_adapter.get_tools_b();

  return 0;
}