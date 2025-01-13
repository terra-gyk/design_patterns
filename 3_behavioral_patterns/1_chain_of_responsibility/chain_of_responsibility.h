#ifndef __CHAIN_OF_RESPONSIBILITY_H__
#define __CHAIN_OF_RESPONSIBILITY_H__

#include <iostream>
#include <memory>

class handler 
{
public:
  virtual std::shared_ptr<handler> set_next(std::shared_ptr<handler> handler) = 0;
  virtual std::string handle(std::string name) = 0;
};

class animal : public handler
{
public:
  std::shared_ptr<handler> set_next(std::shared_ptr<handler> handler) override
  {
    next_handler_ = handler;
    return next_handler_;
  }

  std::string handle(std::string name) override
  {
    if( nullptr != next_handler_ )
    {
      return this->next_handler_->handle(name);
    }
    return {};
  }
private:
  std::shared_ptr<handler> next_handler_;
};

class dog : public animal
{
public:
  std::string handle(std::string name) override
  {
    if( "dog" == name)
    {
      return  "this is dog handle. \n";
    }
    else 
    {
      return  animal::handle(name);
    }
  }
};

class cat : public animal
{
public:
  std::string handle(std::string name) override
  {
    if( "cat" == name)
    {
      return  "this is cat handle. \n";
    }
    else 
    {
      return  animal::handle(name);
    }
  }
};

class rabbit : public animal
{
public:
  std::string handle(std::string name) override
  {
    if( "rabbit" == name)
    {
      return  "this is rabbit handle. \n";
    }
    else 
    {
      return  animal::handle(name);
    }
  }
};

#endif // __CHAIN_OF_RESPONSIBILITY_H__