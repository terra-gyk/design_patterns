/**
 * 简单工厂模式：通过工厂来返回一个具体得对象，而不是使用类构造函数
 * 使用方法：
 *    1. 通过一个工厂构造一个系类得产品
 *    2. 或者使用一个工厂，提供一个产品不同的构造方法
 * 使用构造函数来构造产品，有个弊端是我们不能用它来传递任何额外的信息
 */

#include "product.h"
#include "factory.h"

#include <iostream>

int main()
{
  creator creator;
  auto product_a = creator.create_product_a();
  std::cout << product_a->get_name() << std::endl;

  auto product_b = creator.create_product_b();
  std::cout << product_b->get_name() << std::endl;

  auto product_a_1 = creator.create_product(product_type::A);
  std::cout << product_a_1->get_name() << std::endl;

  auto product_b_1 = creator.create_product(product_type::B);
  std::cout << product_b_1->get_name() << std::endl;
  return 0;
}