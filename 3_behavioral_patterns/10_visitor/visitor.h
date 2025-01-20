#ifndef __VISITOR_H__
#define __VISITOR_H__

#include <iostream>
#include <string>
#include <memory>

class component_a;
class component_b;

class visitor
{
public:
  virtual void visitor_component_a(std::shared_ptr<component_a> component) = 0;
  virtual void visitor_component_b(std::shared_ptr<component_b> component) = 0;
};

class component 
{
public:
  virtual ~component(){}
  virtual void accept(std::shared_ptr<visitor> visitor) = 0;
};

class component_a : public component, public std::enable_shared_from_this<component_a>
{
public:
  void accept(std::shared_ptr<visitor> visitor) override
  {
    visitor->visitor_component_a(shared_from_this());
  }

  void method_of_component_a()
  {
    std::cout << "component a do some.\n";
  }
};

class component_b : public component, public std::enable_shared_from_this<component_b>
{
public:
  void accept(std::shared_ptr<visitor> visitor) override
  {
    visitor->visitor_component_b(shared_from_this());
  }

  void method_of_component_b()
  {
    std::cout << "component b do some.\n";
  }
};

class visitor_a : public visitor
{
public:
  void visitor_component_a(std::shared_ptr<component_a> component)
  {
    std::cout << "visitor a do some && ";
    component->method_of_component_a();
  }
  
  void visitor_component_b(std::shared_ptr<component_b> component)
  {
    std::cout << "visitor a do some && ";
    component->method_of_component_b();
  }
};

class visitor_b : public visitor
{
public:
  void visitor_component_a(std::shared_ptr<component_a> component)
  {
    std::cout << "visitor b do some && ";
    component->method_of_component_a();
  }
  
  void visitor_component_b(std::shared_ptr<component_b> component)
  {
    std::cout << "visitor b do some && ";
    component->method_of_component_b();
  }
};

#endif // __VISITOR_H__