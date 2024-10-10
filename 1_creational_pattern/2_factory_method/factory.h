#ifndef __FACTORY_H__
#define __FACTORY_H__

#include "product.h"

#include <string>
#include <memory>

enum class product_type { A , B };

class creator
{
public:
  using product_ptr = std::unique_ptr<product>;

  ~creator() {}
  product_ptr create_product_a()
  {
    return std::make_unique<concrete_product_a>();

  };
  product_ptr create_product_b()
  {
    return std::make_unique<concrete_product_b>();
  };

  // 或者可以用这种方式
  product_ptr create_product(product_type type)
  {
    switch (type)
    {
    case product_type::A:
      return std::make_unique<concrete_product_a>();
      break;
    case product_type::B:
      return std::make_unique<concrete_product_b>();
      break;
    default:
      return nullptr;
    }
  }
};


#endif // __FACTORY_H__