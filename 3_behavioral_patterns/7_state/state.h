#ifndef __STATE_H__
#define __STATE_H__

#include <iostream>
#include <memory>

class context;

class state
{
public:
  virtual void handle1() = 0;
  virtual void handle2() = 0;
};

class context
{
public:
  using state_ptr = std::shared_ptr<state>;
  context(state_ptr state) : state_(state){}
  void trans_state_to(state_ptr state)
  {
    std::cout << "trans state. \n";
    state_ = state;
  }

  void request1()
  {
    state_->handle1();
  }

  void request2()
  {
    state_->handle2();
  }
private:
  state_ptr  state_;
};

class state_a : public state
{
public:
  void handle1() override
  {
    std::cout << "state a handle1.\n";
  }

  void handle2() override
  {
    std::cout << "state a handle2.\n";
  }
};

class state_b : public state
{
public:
  void handle1() override
  {
    std::cout << "state b handle1.\n";
  }

  void handle2() override
  {
    std::cout << "state b handle2.\n";
  }
};

#endif // __STATE_H__