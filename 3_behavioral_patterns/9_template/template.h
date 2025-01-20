#ifndef __TEMPLATE_H__
#define __TEMPLATE_H__

#include <iostream>
#include <algorithm>
#include <memory>

class abstract_template
{
public:
  void template_method()
  {
    this->step_a();
    this->step_b();
    this->step_c();
    this->step_d();
    this->step_e();
    this->step_f();
    this->step_g();
  }

protected:
  void step_a()
  {
    std::cout << "algorithm step a. \n";
  }
  void step_b()
  {
    std::cout << "algorithm step b. \n";
  }
  void step_c()
  {
    std::cout << "algorithm step c. \n";
  }

  // mandatory step
  virtual void step_d() = 0; 
  virtual void step_e() = 0; 

  // not mandatory step
  virtual void step_f() {}; 
  virtual void step_g() {}; 
};

class template_a : public abstract_template
{
protected: 
  void step_d() override
  {
    std::cout << "template a algorithm step d. \n";
  }

  void step_e() override
  {
    std::cout << "template a algorithm step e. \n";
  }

  void step_g() override
  {
    std::cout << "template a algorithm step g. \n";
  }
};

class template_b : public abstract_template
{
protected: 
  void step_d() override
  {
    std::cout << "template b algorithm step d. \n";
  }

  void step_e() override
  {
    std::cout << "template b algorithm step e. \n";
  }

  void step_f() override
  {
    std::cout << "template b algorithm step g. \n";
  }
};

#endif // __TEMPLATE_H__