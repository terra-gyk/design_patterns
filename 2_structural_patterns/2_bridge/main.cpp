/**
 * 桥接模式是一种结构型设计模式， 可将一个大类或一系列紧密相关的类拆分为抽象和实现两个独立的层次结构， 从而能在开发时分别使用。
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