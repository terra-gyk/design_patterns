#include "person_job_builder.h"

person_job_builder& person_job_builder::at(std::string company_name)
{
  person_.company_name_ = company_name;
  return *this;
}

person_job_builder& person_job_builder::as_a(std::string position)
{
  person_.position_ = position;
  return *this;
}

person_job_builder& person_job_builder::earning(int annual_income)
{
  person_.annual_income_ = annual_income;
  return *this;
}