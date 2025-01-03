#ifndef __DECORATOR_H__
#define __DECORATOR_H__

#include <iostream>
#include <string>
#include <memory>

class hero
{
public:
  virtual void show_skill() = 0;
};

class run_hero : public hero
{
public:
  void show_skill() override
  {
    run_skill();
  }
private:
  void run_skill()
  {
    std::cout << "hero can run.\n";
  }
};

class fly_hero : public hero
{
public:
  fly_hero(std::shared_ptr<hero> hero) : base_hero_(hero) {}
  void show_skill() override 
  {
    base_hero_->show_skill();
    run_skill();
  }

private:
  void run_skill()
  {
    std::cout << "hero can fly.\n";
  }

  std::shared_ptr<hero>  base_hero_;
};

class laser_hero : public hero
{
public:
  laser_hero(std::shared_ptr<hero> hero) : base_hero_(hero) {}
  void show_skill() override 
  {
    base_hero_->show_skill();
    run_skill();
  }

private:
  void run_skill()
  {
    std::cout << "hero can shoot laser.\n";
  }

  std::shared_ptr<hero>  base_hero_;
};

#endif // __DECORATOR_H__