#ifndef __ADAPTER_H__
#define __ADAPTER_H__

#include <iostream>
#include <string>
#include <algorithm>
#include <memory>

/**
 * target method 
 */
class target
{
public:
  virtual std::string request() const
  {
    return "target: the default target behavior.";
  }
};

class adaptee
{
public:
  std::string reverse_request() const 
  {
    return ".roivaheb eetpada tluafed eht :eetpada";
  };
};

/**
 * adapter override target request
 */
class adapter : public target,public adaptee
{
public:
  std::string request() const override 
  {
    std::string old_str = reverse_request();
    std::reverse(old_str.begin(),old_str.end());
    return "adapter behavior:" + old_str;
  }
};

/**
 * old client code
 */
class client  
{
public:
  static void client_code(const std::shared_ptr<target> param)
  {
    std::cout << param->request() << std::endl;
  }
};


/**
 * 或者如果有一些方法不兼容，可以通过一个适配器来增加一个兼容的接口
 */
class tools_a
{
public:
  void get_tools_a()
  {
    std::cout << "use tools a. \n";
  }
};

class tools_b
{
public:
  void get_tools_b()
  {
    std::cout << "use tools b. \n";
  }
};

class tools_adapter : public tools_b
{
public:
  tools_adapter(tools_a a): tools_a_(a){}

  void get_tools_b()
  {
    tools_a_.get_tools_a();
    tools_a_to_tools_b();
    std::cout << "use tools b. \n";
  }
private:
  void tools_a_to_tools_b()
  {
    std::cout << "change tools a to tools b. \n";
  }

  tools_a     tools_a_;
};










#endif // __ADAPTER_H__