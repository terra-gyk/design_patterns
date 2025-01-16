/**
 * 迭代器模式是一种行为设计模式， 让你能在不暴露集合底层表现形式 （列表、 栈和树等） 的情况下遍历集合中所有的元素。
 * 可以参考 stl 中迭代器的实现，迭代器一定是基于某个容器的
 */

#include "iterator.h"


int main()
{
  int num[10] = {1,2,3,4,5,6,7,8,9,10};
  container<int,3> arr{num};
  container<int,3>::iterator ii = arr.begin();

  for( ; ii != arr.end(); ii++)
  {
    std::cout <<  *ii << std::endl;
  }

  return 0;
}