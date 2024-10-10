#ifndef __PRODUCT_H__
#define __PRODUCT_H__

#include <string>

class product 
{
public:
  virtual std::string get_name() = 0;

};

class concrete_product_a : public product
{
public:
  std::string get_name() override { return "product a"; } 
};

class concrete_product_b : public product
{
public:
  std::string get_name() override { return "product b"; } 
};

class concrete_product_c : public product
{
public:
  concrete_product_c(){};
  std::string get_name() override { return "product c"; } 
private:
  std::string name_;
};

#endif // __PRODUCT_H__