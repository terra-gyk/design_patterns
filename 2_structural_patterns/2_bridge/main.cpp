/**
 * 桥接模式是一种结构型设计模式， 可将一个大类或一系列紧密相关的类拆分为抽象和实现两个独立的层次结构， 从而能在开发时分别使用。
 * 抽象部分（Abstraction）提供高层控制逻辑，依赖于完成底层实际工作的实现对象。
 * 实现部分（Implementation）为所有具体实现声明通用接口。抽象部分仅能通过在这里声明的方法与实现对象交互。
 * c++ 的 pimpl 就是桥接模式的特例 
 * 将m*n个实现类转换为m+n个实现类
 */

#include "bridge.h"

int main()
{
  std::shared_ptr<color> blue(new color_blue);
  shape_circle circle(blue);
  std::cout << circle.smear_color() << std::endl;
  return 0;
}