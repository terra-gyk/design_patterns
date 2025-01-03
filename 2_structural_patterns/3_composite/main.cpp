/**
 * 组合是一种结构型设计模式，你可以使用它将对象组合成树状结构，并且能像使用独立对象一样使用它们
 * 比如公司的组织架构，就是一个典型的树状结构
 */

#include "composite.h"

int main()
{
  // 创建组织架构
  auto company = std::make_shared<organization_unit>("公司");

  auto dev_team = std::make_shared<organization_unit>("开发团队");
  dev_team->add(std::make_shared<employee>("张三", "开发工程师"));
  dev_team->add(std::make_shared<employee>("李四", "开发工程师"));

  auto sales_team = std::make_shared<organization_unit>("销售团队");
  sales_team->add(std::make_shared<employee>("王五", "销售经理"));

  company->add(dev_team);
  company->add(sales_team);

  // 显示组织架构
  company->display(0);

  return 0;
}