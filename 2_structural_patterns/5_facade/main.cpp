/**
 * 外观模式是一种结构型设计模式， 能为程序库、 框架或其他复杂类提供一个简单的接口。
 * 如果你需要一个指向复杂子系统的直接接口，且该接口的功能有限，则可以使用外观模式。
 * 大概的思想就是，只提供一个抽象的接口，而接口下做了什么事，用户无需考虑。
 * 比如自动贩卖机，是对外提供的外观，用户只需要选择饮料以及投币，至于贩卖机如何验证钱数，如何将饮料送至客户手里，这个过程用户不可见或者说不必关心。
 */

#include "facade.h"

int main()
{
  // 大概就是将原本比较散乱的一些方法包装起来，由一个统一的接口去提供
  // 比如这里，如果要画图形，原本需要生成多个多个对象，现在只需要生成一个shape_maker就可以画出不同的图形
  // 
  cicle cicle;
  cicle.draw();
  rectangle rectangle;
  rectangle.draw();

  shape_maker maker;
  maker.draw_cicle();
  maker.draw_rectangle();
  maker.draw_all();
  
  return 0;
}