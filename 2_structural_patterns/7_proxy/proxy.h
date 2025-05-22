#ifndef __PROXY_H__
#define __PROXY_H__

#include <iostream>
#include <memory>

class subject 
{
public:  
  virtual void request() = 0;
};

class real_subject : public subject
{
public:
  real_subject()
  {
    std::cout << "construct real subject.\n";
  }

  void request() override
  {
    std::cout << "this is real subject handle request.\n";
  }
};

class proxy : public subject
{
public:
  proxy(std::shared_ptr<subject> subject) 
    : real_subject_(subject)
  {
  }

  void request() override
  {
    this->check_access();
    this->real_subject_->request();
  }

private:
  bool check_access()
  {
    std::cout << "check subject access.\n"; 
    if( nullptr != real_subject_ )
    {
      return true;
    }
    return false;
  }
  std::shared_ptr<subject>  real_subject_;
};

#endif // __PROXY_H__