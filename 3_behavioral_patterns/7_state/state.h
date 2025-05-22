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
  virtual std::string get_state() const = 0;
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

  std::string get_state() const override { return state_; }
private:
  std::string state_ = "state a";
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

  std::string get_state() const override { return state_; }
private:
  std::string state_ = "state b";
};

class context
{
public:
  using state_ptr = std::shared_ptr<state>;
  context(state_ptr state) 
    : state_(state)
  {
  }
  
  void trans_state_to(state_ptr state)
  {
    std::cout << "trans state to " << state->get_state() << "\n";
    state_ = state;
  }

  void request1()
  {
    state_->handle1();
    this->trans_state_to(std::make_shared<state_b>());
  }

  void request2()
  {
    state_->handle2();
    this->trans_state_to(std::make_shared<state_a>());
  }
private:
  state_ptr  state_;
};

#endif // __STATE_H__