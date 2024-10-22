#ifndef __PROTOTYPE_H__
#define __PROTOTYPE_H__

/**
 * 请注意，这里只是简单的示例，数据成员为 std::string 而非指针，如果是指针成员，需要做深拷贝（或者对象成员需要支持深拷贝）
 * 序列化的方式这里没有实现
 */

#include <iostream>
#include <memory>
#include <map>

class prototype
{
public:
  virtual std::unique_ptr<prototype> clone() = 0; 
  virtual std::string type() = 0; 
};

class concrete_prototype_a : public prototype
{
public:
  concrete_prototype_a() = default;
  concrete_prototype_a(const concrete_prototype_a* other):type_(other->type_){}
  concrete_prototype_a(const concrete_prototype_a& other):type_(other.type_){}

  std::unique_ptr<prototype> clone() override
  {
    return std::make_unique<concrete_prototype_a>(this);
  } 
  std::string type() override
  {
    return type_;
  }
private:
  std::string type_ = "concrete_prototype_a";
};

class concrete_prototype_b : public prototype
{
public:
  concrete_prototype_b() = default;
  concrete_prototype_b(const concrete_prototype_b* other):type_(other->type_){}
  concrete_prototype_b(const concrete_prototype_b& other):type_(other.type_){}

  std::unique_ptr<prototype> clone() override
  {
    return std::make_unique<concrete_prototype_b>(this);
  } 
  std::string type() override
  {
    return type_;
  }
private:
  std::string type_ = "concrete_prototype_b";
};

class client
{
public:
  void init()
  {
    if( prototypes_.find("a") == prototypes_.end()) 
    {
      prototypes_.emplace("a",std::make_unique<concrete_prototype_a>());
    }

    if( prototypes_.find("b") == prototypes_.end()) 
    {
      prototypes_.emplace("b",std::make_unique<concrete_prototype_b>());
    }
  }

  std::unique_ptr<prototype> get_prototype(std::string type)
  {
    if( prototypes_.find(type) != prototypes_.end())
    {
      return prototypes_[type]->clone();
    }
    return nullptr;
  }

private:
  static std::map<std::string, std::unique_ptr<prototype> >   prototypes_;
};

std::map<std::string, std::unique_ptr<prototype> >   client::prototypes_ = {};

#endif // __PROTOTYPE_H__