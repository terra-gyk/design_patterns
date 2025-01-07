/**
 * 享元模式 （flyweight 的意思是轻量级）
 * 享元模式是一种结构型设计模式， 它摒弃了在每个对象中保存所有数据的方式， 通过共享多个对象所共有的相同状态， 让你能在有限的内存容量中载入更多对象。 
 * 经典场景游戏中的子弹，如果每个子弹都存在一个实例，那么内存很容易爆炸
 * 对象的常量数据通常被称为内在状态，其位于对象中，其他对象只能读取但不能修改其数值。而对象的其他状态常常能被其他对象“从外部”改变，因此被称为外在状态。
 * 享元模式建议不在对象中存储外在状态，而是将其传递给依赖于它的一个特殊方法。程序只在对象中保存内在状态，以方便在不同情景下重用。
 * 我们将这样一个仅存储内在状态的对象称为享元。
 */

#include "flyweight.h"

int main()
{
  car_factory factory;
  car terra_car("terra","123456");
  factory.get_car("888", "rubber");
  factory.get_car("999", "rubber1");
  factory.get_car("999", "rubber1");
  terra_car.set_shared_part(factory.get_car("888", "rubber"));
  terra_car.display();

  return 0;
}