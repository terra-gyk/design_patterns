#include "person_address_builder.h"

person_address_builder& person_address_builder::at(std::string street_address)
{
  person_.street_address_ = street_address;
  return *this;
}

person_address_builder& person_address_builder::with_postcode(std::string post_code)
{
  person_.post_code_ = post_code;
  return *this;
}

person_address_builder& person_address_builder::in(std::string city)
{
  person_.city_ = city;
  return *this;
}