/**
 * 模板方法模式是一种行为设计模式，它在超类中定义了一个算法的框架，允许子类在不修改结构的情况下重写算法的特定步骤。
 */

#include "template.h"

int main()
{
  auto template_1 = std::make_shared<template_a>();
  template_1->template_method();
  auto template_2 = std::make_shared<template_b>();
  template_2->template_method();
  return 0;
}