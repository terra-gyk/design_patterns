#ifndef __STRATEGY_H__
#define __STRATEGY_H__

#include <iostream>
#include <algorithm>
#include <memory>

class strategy
{
public:
  virtual std::string do_algorithm(std::string data) = 0;
};

class context
{
public:
  void set_strategy(std::shared_ptr<strategy>&& strategy)
  {
    strategy_ = strategy;
  }

  void do_some(std::string data)
  {
    if( nullptr != strategy_ )
    {
      std::cout << "context do some algorithm.\n";
      std::cout << "res is: " << strategy_->do_algorithm(data) << "\n";
    }
    else 
    {
      std::cout << "context do not set strategy. \n";
    }
  }
private:
  std::shared_ptr<strategy> strategy_;
};

class strategy_a : public strategy
{
public:
  std::string do_algorithm(std::string data) override
  {
    std::sort(data.begin(),data.end(),[](char a,char b)->bool{return a > b;});
    return data;
  }
};

class strategy_b : public strategy
{
public:
  std::string do_algorithm(std::string data) override
  {
    std::sort(data.begin(),data.end(),[](char a,char b)->bool{return a < b;});
    return data;
  }
};

#endif // __STRATEGY_H__