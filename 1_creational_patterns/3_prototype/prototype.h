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
  concrete_prototype_a(const concrete_prototype_a* other)
    : type_(other->type_)
  {
  }
  concrete_prototype_a(const concrete_prototype_a& other)
    : type_(other.type_)
  {
  }

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
  concrete_prototype_b(const concrete_prototype_b* other)
    : type_(other->type_)
  {
  }
  concrete_prototype_b(const concrete_prototype_b& other)
    : type_(other.type_)
  {
  }

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
    if( prototypes.find("a") == prototypes.end() ) 
    {
      prototypes.emplace("a",std::make_unique<concrete_prototype_a>());
    }

    if( prototypes.find("b") == prototypes.end() ) 
    {
      prototypes.emplace("b",std::make_unique<concrete_prototype_b>());
    }
  }

  std::unique_ptr<prototype> get_prototype(std::string type)
  {
    if( prototypes.find(type) != prototypes.end() )
    {
      return prototypes[type]->clone();
    }
    return nullptr;
  }

private:
  static std::map<std::string, std::unique_ptr<prototype>> prototypes;
};

// 静态成员应该放在 .cpp 文件中初始化，这里只是示例代码，不做强制要求
std::map<std::string, std::unique_ptr<prototype>> client::prototypes = {};
#endif // __PROTOTYPE_H__