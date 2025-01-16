/**
 * 责任链模式是一种行为设计模式， 允许你将请求沿着处理者链进行发送。 收到请求后， 每个处理者均可对请求进行处理， 或将其传递给链上的下个处理者。
 */

#include "chain_of_responsibility.h"

#include <vector>

int main()
{
  std::shared_ptr<handler> dog_handle = std::make_shared<dog>();
  std::shared_ptr<handler> cat_handle = std::make_shared<cat>();
  std::shared_ptr<handler> rabbit_handle = std::make_shared<rabbit>();
  
  dog_handle->set_next(cat_handle)->set_next(rabbit_handle);

  std::vector<std::string> name_arr{ "dog", "cat","rabbit"};

  for(auto name : name_arr)
  {
    std::cout << dog_handle->handle(name);
  }
  return 0;
}