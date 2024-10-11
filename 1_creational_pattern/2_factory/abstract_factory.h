#include <iostream>
#include <memory>
#include <map>

class hot_drink
{
public:
  virtual void prepare(int time) = 0;
};

class tea : public hot_drink
{
public:
  void prepare(int time) override 
  {
    std::cout << "tea is coking please wait " << time << " min\n";
  }
};

class coffee : public hot_drink
{
public:
  void prepare(int time) override 
  {
    std::cout << "coffee is coking please wait " << time << " min\n";
  }
};

class hot_drink_factory
{
public:
  virtual std::unique_ptr<hot_drink> make() = 0;
};

class tea_factory : public hot_drink_factory
{
public:
  std::unique_ptr<hot_drink> make() override
  {
    return std::make_unique<tea>();
  };
};

class coffee_factory : public hot_drink_factory
{
public:
  std::unique_ptr<hot_drink> make() override
  {
    return std::make_unique<coffee>();
  };
};

class drink_factory
{
public:
  drink_factory()
  {
    hot_factories_["tea"] = std::make_unique<tea_factory>();
    hot_factories_["coffee"] = std::make_unique<coffee_factory>();
  }

  std::unique_ptr<hot_drink> make_drink(const std::string& name)
  {
    std::unique_ptr<hot_drink> drink = nullptr;
    auto factory = hot_factories_.find(name);
    if( factory != hot_factories_.end() )
    {
      drink = hot_factories_[name]->make();
      drink->prepare(200); // oops! 
    }
    else
    {
      std::cout << "unkonw drink\n";
    }
    return drink;
  }

private:
  std::map<std::string, std::unique_ptr<hot_drink_factory>> hot_factories_;
};