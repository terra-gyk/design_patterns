#include "person.h"
#include "person_builder.h"

#include <iostream>

person_builder person::create()
{
  return person_builder{};
}

std::ostream& operator<<(std::ostream& output, const person& person)
{
  std::cout << "          city : " << person.city_ << "\n";
  std::cout << "street_address : " << person.street_address_ << "\n";
  std::cout << "     post_code : " << person.post_code_ << "\n";

  std::cout << "  company_name : " << person.company_name_ << "\n";
  std::cout << "      position : " << person.position_ << "\n";
  std::cout << " annual_income : " << person.annual_income_ << "\n";
  return output;
}