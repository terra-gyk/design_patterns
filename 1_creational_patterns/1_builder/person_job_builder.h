#ifndef __PERSON_JOB_BUILDER_H__
#define __PERSON_JOB_BUILDER_H__

#include "person_builder.h"

class person_job_builder : public person_builder_base
{
public:
  explicit person_job_builder(person& person) 
    : person_builder_base{person}
  {
  }

  person_job_builder& at(std::string company_name);
  person_job_builder& as_a(std::string position);
  person_job_builder& earning(int annual_income);
};

#endif // __PERSON_JOB_BUILDER_H__