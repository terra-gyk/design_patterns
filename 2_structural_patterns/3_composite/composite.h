#ifndef __COMPOSITE_H__
#define  __COMPOSITE_H__

#include <iostream>
#include <list>
#include <memory>

class company
{
public:
  company(std::string name):name_(name){}
  using company_ptr = std::shared_ptr<company>;
          
	virtual void add(company_ptr node) = 0;            // 增加一个部门
	virtual void remove(company_ptr node) = 0;         // 移除一个部门 
  virtual void set_parent(company_ptr node) = 0;     // 设置父级组织

  virtual std::string display() = 0;                 // 当前公司 / 部门 / 员工的名称

  std::string get_name() const {return name_; }      // 获取名称
	std::list<company_ptr> get_child() const           // 获取公司下属部门
  {
    return child_;
  };  

protected:
  company_ptr parent_;
  std::string name_;
  std::list<company_ptr> child_;
};

class company_a : public company
{
public:
  company_a(std::string name): company(name){}

  void add(company_ptr node) override
  {
    child_.push_back(node);
  }

  void remove(company_ptr node) override
  {
    child_.remove(node);
  }

  std::string display() override
  {
    return parent_ ? parent_->display() + "/" + name_ : name_;
  }
};

class department : public company
{
public:
  department(std::string name): company(name){}

  void add(company_ptr node) override
  {
    child_.push_back(node);
  }

  void remove(company_ptr node) override
  {
    child_.remove(node);
  }
};

class employ : public company
{
public:
  employ(std::string name): company(name){}

  void add(company_ptr node) override
  {
    child_.push_back(node);
  }

  void remove(company_ptr node) override
  {
    child_.remove(node);
  }
};


#endif //__COMPOSITE_H__