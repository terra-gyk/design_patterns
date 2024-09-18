#include <cstdio>

enum class Color { Red, Green, Blue };
enum class Size { Small, Medium, Large };

template <typename T> 
struct Specification
{
  virtual bool is_satisfied(T* item) = 0;
};

template <typename T> struct Filter
{
  virtual vector<T*> filter(vector<T*> items,
                            Specification<T>& spec ) = 0;
};

int main()
{

}