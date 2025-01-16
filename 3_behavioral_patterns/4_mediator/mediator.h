#ifndef __MEDIATOR_H__
#define __MEDIATOR_H__

#include <iostream>
#include <memory>

enum class mediator_event { A, B, C, D };

class base_component;

class mediator
{
public:
  virtual void notify(mediator_event event) = 0;
};

class base_component
{
public:
  void set_mediator(std::shared_ptr<mediator> mediator) 
  { 
    mediator_ = mediator;
  }

protected:
  std::shared_ptr<mediator>  mediator_;
};

class component_a : public base_component 
{
public:
  void do_some()
  {
    std::cout << "component a do some. \n";
    this->mediator_->notify(mediator_event::B);
  }

  void some_for_b()
  {
    std::cout << "component a do some for b. \n";
  }
};

class component_b : public base_component 
{
public:
  void do_some()
  {
    std::cout << "component b do some. \n";
    this->mediator_->notify(mediator_event::A);
  }

  void some_for_a()
  {
    std::cout << "component b do some for a. \n";
  }
};

class sample_mediator : public mediator
{
public:
  sample_mediator(std::shared_ptr<component_a> a, std::shared_ptr<component_b> b):component_a_(a),component_b_(b){}
  void notify(mediator_event event)
  {
    switch (event) 
    {
      case mediator_event::A:
        std::cout << "notify a. \n";
        component_a_->some_for_b();
        break;
      case mediator_event::B:
        std::cout << "notify b. \n";
        component_b_->some_for_a();
        break;
      case mediator_event::C:
        break;
      case mediator_event::D:
        break;
      default:
        std::cout << "event not support in sample mediator.\n";
        break;
    }
  }
private:
  std::shared_ptr<component_a>  component_a_;
  std::shared_ptr<component_b>  component_b_;
};



#endif // __MEDIATOR_H__