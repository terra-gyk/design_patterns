#ifndef __PERSON_BUILDER_H__
#define __PERSON_BUILDER_H__

#include "person.h"

// 提供各部分的构造
class person_address_builder;
class person_job_builder;

// 存储对象的引用
class person_builder_base 
{
public:
  // 类型转换运算符
  operator person() const
  {
    return std::move(person_);
  }

  // builder 的两个部分
  person_address_builder lives() const;
  person_job_builder works() const;

protected:
  person& person_;
  explicit person_builder_base(person& person): person_{ person }{}
};

// 存储对象德实体
class person_builder : public person_builder_base
{
public:
  person_builder(): person_builder_base{person_}{}

protected:
  person person_;
};


#endif // __PERSON_BUILDER_H__