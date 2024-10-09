#ifndef __PERSON_BUILDER_H__
#define __PERSON_BUILDER_H__

#include "person.h"

class person_address_builder;
class person_job_builder;

class person_builder_base // 存储对象的引用
{
public:
  // 类型转换运算符
  operator person() const
  {
    return std::move(person_);
  }

  // builder facets
  person_address_builder lives() const;
  person_job_builder works() const;

protected:
  person& person_;
  explicit person_builder_base(person& person): person_{ person }{}
};

class person_builder : public person_builder_base
{
public:
  person_builder(): person_builder_base{person_}{}

protected:
  person person_;
};


#endif // __PERSON_BUILDER_H__