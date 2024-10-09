#ifndef __PERSON_H__
#define __PERSON_H__

#include <string>

class person_builder;

class person 
{
public:
  person() {}

  static person_builder create(); 

  friend std::ostream& operator<<(std::ostream& output, const person& person);

private:
  friend class person_builder;
  friend class person_address_builder;
  friend class person_job_builder;

  // address
  std::string  street_address_; 
  std::string  post_code_;
  std::string  city_;

  // employment
  std::string  company_name_;
  std::string  position_;
  int          annual_income_ = 0;
};


#endif // __PERSON_H__