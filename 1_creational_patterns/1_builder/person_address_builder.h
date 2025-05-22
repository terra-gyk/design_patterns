#ifndef __PERSON_ADDRESS_BUILDER_H__
#define __PERSON_ADDRESS_BUILDER_H__

#include "person_builder.h"

class person_address_builder : public person_builder_base
{
public:
  explicit person_address_builder(person& person) 
    : person_builder_base{person}
  {
  }

  person_address_builder& at(std::string street_address);
  person_address_builder& with_postcode(std::string post_code);
  person_address_builder& in(std::string city);
};

#endif // __PERSON_ADDRESS_BUILDER_H__