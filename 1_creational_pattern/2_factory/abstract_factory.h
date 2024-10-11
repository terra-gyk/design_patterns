#include <iostream>
#include <memory>
#include <map>
#include <functional>

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
    factories_["tea"] = std::make_unique<tea_factory>();
    factories_["coffee"] = std::make_unique<coffee_factory>();
  }

  std::unique_ptr<hot_drink> make_drink(const std::string& name)
  {
    std::unique_ptr<hot_drink> drink = nullptr;
    auto factory = factories_.find(name);
    if( factory != factories_.end() )
    {
      drink = factories_[name]->make();
      drink->prepare(200); 
    }
    else
    {
      std::cout << "unkonw drink\n";
    }
    return drink;
  }

private:
  std::map<std::string, std::unique_ptr<hot_drink_factory>> factories_;
};


// 或者这么写
class drink_factory_with_wait 
{
public:
  drink_factory_with_wait()
  {
    factories_["tea"] = []
    {
      auto hot_tea = std::make_unique<tea>();
      hot_tea->prepare(200);
      return hot_tea;
    };
    factories_["coffee"] = []
    {
      auto hot_coffee = std::make_unique<coffee>();
      hot_coffee->prepare(200);
      return hot_coffee;
    };
  }

  inline std::unique_ptr<hot_drink> make_drink(const std::string& name)
  {
    std::unique_ptr<hot_drink> drink = nullptr;
    auto factory = factories_.find(name);
    if( factory != factories_.end() )
    {
      drink = factory->second();
    }
    else
    {
      std::cout << "unkonw drink\n";
    }
    return drink; 
  }
private:
  std::map<std::string, std::function<std::unique_ptr<hot_drink>()>> factories_;
};