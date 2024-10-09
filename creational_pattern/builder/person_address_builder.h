#ifndef __PERSON_ADDRESS_BUILDER_H__
#define __PERSON_ADDRESS_BUILDER_H__


class person_address_builder : public person_builder_base
{
public:
  explicit person_address_builder(person& person) : person_builder_base{person}{}

  person_address_builder& at(std::string street_address)
  {
    person_.street_address_ = street_address;
    return *this;
  }

  person_address_builder& with_postcode(std::string post_code)
  {
    person_.post_code_ = post_code;
    return *this;
  }

  person_address_builder& in(std::string city)
  {
    person_.city_ = city;
    return *this;
  }
};

#endif // __PERSON_ADDRESS_BUILDER_H__