/**
 * 建造者模式（`Builder`）涉及到复杂对象的创建，即不能在单行构造函数调用中构建的对象。
 * 这些类型的对象本身可能由其他对象组成，可能涉及不太明显的逻辑，需要一个专门用于对象构造的单独组件。
 */

#include "person.h"
#include "person_builder.h"
#include "person_address_builder.h"
#include "person_job_builder.h"

#include <iostream>

int main()
{
  person p = person::create().lives().at("123 London Road").with_postcode("SW1 1GB").in("London").works().at("PragmaSoft").as_a("Consultant").earning(10e6);

  std::cout << p << std::endl;

  return 0;
}