#ifndef  __COMMAND_H__
#define  __COMMAND_H__

#include <iostream>
#include <vector>
#include <memory>

class command
{
public:
  virtual void execute() const = 0;
};


class receiver_a
{
public:
  void do_something(std::string some)
  {
    std::cout << "receiver a do some 1: " << some << "\n"; 
  }
};

class receiver_b
{
public:
  void do_something(std::string some)
  {
    std::cout << "receiver b do some 2: " << some << "\n"; 
  }
};

class command_a : public command
{
public:
  command_a(std::shared_ptr<receiver_a> receiver, std::string some): receiver_(receiver),some_(some){} 

  void execute() const override
  {
    receiver_->do_something(some_);
  }
private:
  std::shared_ptr<receiver_a>   receiver_;
  std::string                   some_;
};

class command_b : public command
{
public:
  command_b(std::shared_ptr<receiver_b> receiver, std::string some): receiver_(receiver),some_(some){} 
  void execute() const override
  {
    receiver_->do_something(some_);
  }
private:
  std::shared_ptr<receiver_b>   receiver_;
  std::string                   some_;
};

class invoke
{
public:
  void add_command(std::shared_ptr<command> command)
  {
    commands_.push_back(command);
  }

  void execute_command()
  {
    for(auto command : commands_)
    {
      if( nullptr != command)
      {
        command->execute();
      }
    }
  }

private:
  std::vector<std::shared_ptr<command>> commands_; 
};

#endif // __COMMAND_H__