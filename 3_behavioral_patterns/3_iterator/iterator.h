#ifndef  __ITERATOR_H__
#define  __ITERATOR_H__

/**
 * Iterator Design Pattern
 *
 * Intent: Lets you traverse elements of a collection without exposing its
 * underlying representation (list, stack, tree, etc.).
 */

#include <iostream>
#include <string>
#include <vector>

template<typename P>
class base_iterator
{
public:
  base_iterator(P* p) : data_point_(p){}

  bool operator==(base_iterator that)
  {
    return this->data_point_ == that.data_point_;
  }

  bool operator!=(base_iterator that)
  {
    return !(this->data_point_ == that.data_point_);
  }

  base_iterator& operator++(int)
  {
    this->data_point_ = this->data_point_ + 1;
    return *this;
  }

  P& operator*() const 
  {
    return *data_point_;
  }

  friend std::ostream& operator<<(std::ostream& os, const base_iterator<P>& iter)
  {
    os << *iter.data_point_;
    return os;
  }

private:
  P*     data_point_;
}; 

template<typename T, int size = 20>
class container 
{
public:
  using iterator = base_iterator<T>;

  // 这个构造实现很粗糙，不是很建议这么用
  container(T* data)
  {
    for(int index = 0; index < size; index++)
    {
      data_[index] = data[index];
    }
  };

  iterator begin()
  {
    return iterator{data_};
  };

  iterator end()
  {
    return iterator{data_ + size};
  };
private:
  T            data_[size];
};

#endif // __ITERATOR_H__