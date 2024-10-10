/**
 * 简单工厂模式：通过工厂来返回一个具体对象，而不是使用类构造函数
 * 使用方法：
 *    1. 提供不同的函数来构造不同的产品
 *    2. 通过传参来构造不同产品
 * ps: 使用构造函数来构造产品，有个弊端是我们不能用它来传递任何额外的信息
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

  auto product_c_1 = creator.create_product_c_by_age(25);
  std::cout << product_c_1->get_name() << std::endl;

  auto product_c_2 = creator.create_product_c_by_name("terra");
  std::cout << product_c_1->get_name() << std::endl;
  return 0;
}