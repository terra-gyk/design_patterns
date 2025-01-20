#ifndef __OBSERVER_H__
#define __OBSERVER_H__

#include <iostream>
#include <memory>
#include <set>
#include <chrono>

class i_observer
{
public:
  virtual void update(std::string message) = 0;
};

class i_subject
{
public:
  virtual void add_observer(std::shared_ptr<i_observer> observer) = 0;
  virtual void remove_observer(std::shared_ptr<i_observer> observer) = 0;
  virtual void notify() = 0;
};

class subject : public i_subject
{
public:
  using observer_list = std::set<std::shared_ptr<i_observer>>;

  void do_some()
  {
    std::cout << "subject have a new message notify all observer.\n";
    new_message_ = this->generate_random_string(30);
    this->notify();
  }

  void add_observer(std::shared_ptr<i_observer> observer) override
  {
    if( observers_.count(observer) == 0 )
    {
      std::cout << "subject have a new observer.\n";
      observers_.emplace(observer);
    }
  }

  void remove_observer(std::shared_ptr<i_observer> observer) override
  {
    std::cout << "subject have a observer leave.\n";
    observers_.erase(observer);
  }

  void notify() override
  {
    for( auto observe : observers_)
    {
      observe->update(new_message_);
    }
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

  std::string    new_message_;
  observer_list  observers_; 
};

class observer : public i_observer
{
public:
  observer()
  {
    number_ = std::chrono::system_clock::now();
  }

  void update(std::string message) override
  {
    std::cout << "subject update notify observer: " << number_.time_since_epoch().count() << "\n";
  }

private:
  std::chrono::system_clock::time_point   number_;
};

#endif // __OBSERVER_H__