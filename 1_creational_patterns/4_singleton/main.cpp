/**
 * 单例模式：应用程序中应该只有一个特定组件的实例。
 * 
 */

#include "singleton.h"

#include <iostream>

int main()
{
  static_cpp11::get_instance().print();
  double_check::get_instance()->print();
  double_check::destroy_instrance();
};