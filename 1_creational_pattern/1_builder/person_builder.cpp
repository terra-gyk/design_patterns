#include "person_builder.h"
#include "person_address_builder.h"
#include "person_job_builder.h"

person_address_builder person_builder_base::lives() const
{
  return person_address_builder{ person_ };
}

person_job_builder person_builder_base::works() const
{
  return person_job_builder{ person_ };
} 