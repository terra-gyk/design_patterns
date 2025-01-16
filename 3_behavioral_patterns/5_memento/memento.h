#ifndef __MEMENTO_H__
#define __MEMENTO_H__

#include <iostream>
#include <string>
#include <memory>
#include <list>
#include <ctime>

class memento
{
public:
  virtual std::string state() const = 0;
  virtual std::string date() const = 0;
  virtual std::string get_record() const = 0;
};

class simple_memento : public memento
{
public:
  simple_memento(std::string state):state_(state)
  {
    this->state_ = state;
    std::time_t now = std::time(0);
    this->date_ = std::ctime(&now);
    this->date_.resize(this->date_.size() -1);
  }

  std::string state() const override {return state_;}
  std::string date() const override {return date_;}
  std::string get_record() const override { return date_ + " : " + state_;}

private:
  std::string state_;
  std::string date_;
};

class originator
{
public:
  originator() : state_( generate_random_string(30) ) 
  {
    std::cout << "originator state is " << state_ << "\n";
  } 
  
  void do_some()
  {
    std::cout << "originator change state to " << state_ << "\n";
  }

  std::shared_ptr<memento> save()
  {
    return std::make_shared<simple_memento>(this->state_);
  }

  void restore(std::shared_ptr<memento> history)
  {
    this->state_ = history->state();
    std::cout << "restore state to " << this->state_ << "\n";
  }

private:
  std::string generate_random_string(int length = 10) {
    static const char alphanum[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    static int string_length = sizeof(alphanum) - 1;
    std::string random_string;
    for (int i = 0; i < length; i++) {
      random_string += alphanum[std::rand() % string_length];
    }
    return random_string;
  }

  std::string  state_;
};

class caretaker
{
public:
  caretaker(std::shared_ptr<originator> originator) : originator_(originator) {}

  void backup()
  {
    std::cout << "save state. \n";
    histories_.push_back(originator_->save());
  }

  void undo()
  {
    if( histories_.empty() )
    {
      return ;
    }
    auto bak = histories_.back();
    histories_.pop_back();
    try 
    {
      originator_->restore(bak);
    } 
    catch (...) 
    {
      this->undo();
    }
  }

  void show_history()
  {
    for(auto node : histories_)
    {
      std::cout << node->get_record() << "\n";
    }
  }

private:
  std::list<std::shared_ptr<memento>> histories_;
  std::shared_ptr<originator> originator_;
};

#endif // __MEMENTO_H__