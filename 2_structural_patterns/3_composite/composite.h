#ifndef __COMPOSITE_H__
#define  __COMPOSITE_H__

#include <iostream>
#include <list>
#include <memory>
#include <exception>

class t_exception : public std::exception 
{
public:
  t_exception(const std::string& msg) : message(msg) {}

  const char* what() const noexcept override 
  {
    return message.c_str();
  }
private:
  std::string message;
};

class compoent
{
public:
  virtual void add(std::shared_ptr<compoent> node) = 0;
  virtual void remove(std::shared_ptr<compoent> node) = 0;
  virtual void display(int depth) = 0;
};

class employee : public compoent 
{
public:
  employee(std::string name, std::string position):name_(name),position_(position){}

  void add(std::shared_ptr<compoent> node) override 
  {
    throw t_exception("employee not allow add");
  };
  void remove(std::shared_ptr<compoent> node) override {};

  void display(int depth) override
  {
    std::cout << std::string(depth * 2, ' ') << name_ << "(" << position_ << ")" << std::endl; 
  }

private:
  std::string   name_;
  std::string   position_;
};

class organization_unit : public compoent
{
public:
  organization_unit(std::string name) : name_(name){}

  void add(std::shared_ptr<compoent> node) override
  {
    childs_.push_back(node);
  }

  void remove(std::shared_ptr<compoent> node) override
  {
    childs_.remove(node);
  }

  void display(int depth) override
  {
    std::cout << std::string(depth * 2, ' ') << name_ << std::endl;
    for(auto node : childs_) 
    {
      node->display(depth + 1);
    }
  }

private:
  std::string                                 name_;
  std::list<std::shared_ptr<compoent>>        childs_;
};


#endif //__COMPOSITE_H__