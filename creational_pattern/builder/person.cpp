#include "person.h"
#include "person_builder.h"

#include <iostream>

person_builder person::create()
{
  return person_builder{};
}

std::ostream& operator<<(std::ostream& output, const person& person)
{
  output << "          city : " << person.city_ << "\n";
  output << "street_address : " << person.street_address_ << "\n";
  output << "     post_code : " << person.post_code_ << "\n";

  output << "  company_name : " << person.company_name_ << "\n";
  output << "      position : " << person.position_ << "\n";
  output << " annual_income : " << person.annual_income_ << "\n";
  return output;
}