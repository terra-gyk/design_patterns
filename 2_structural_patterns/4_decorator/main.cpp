/**
 * 装饰器模式是一种结构型设计模式， 允许你通过将对象放入包含行为的特殊封装对象中来为原对象绑定新的行为。
 * Component：被装饰的主体，定义了一个对象接口，可以给这些对象增加装饰功能；
 * ConcreteComponent：具体的对象，继承于Component；
 * Decorator：装饰者，继承于Component并从Component类的外部完成对Component类功能的扩充，并且Component类并不需要知道装饰者的存在；
 */

#include "decorator.h"

int main()
{
  auto run_hero_1 = std::make_shared<run_hero>();
  auto fly_hero_1 = std::make_shared<fly_hero>(run_hero_1);
  auto laser_hero_1 = std::make_shared<laser_hero>(fly_hero_1);

  run_hero_1->show_skill();
  std::cout << "hero upgrade.\n"; 
  fly_hero_1->show_skill();
  std::cout << "hero upgrade.\n"; 
  laser_hero_1->show_skill();
  return 0;
}