/**
 * 开闭原则
 * 对扩展开放：模块或者类的行为应当可以通过添加新的代码来扩展，而不是通过修改已有代码来实现。这意味着应该可以轻松地添加新的功能或者特性，而不必担心会破坏现有的代码。
 * 对修改关闭：一旦一个模块或者类通过了测试并且被部署，就不应该再修改它，除非是为了修复错误。修改已有的代码可能会导致引入新的错误，并且可能需要重新测试所有依赖于修改部分的代码。
 * 
 * 如下代码，Filter 是不变的，我们可以通过增加 specification 的类型来增加过滤规则
 * 如果需要多重过滤，也可以新增一个 multi specification 的类型来实现，而不用修改 filter
 */



#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;
using std::cout;
using std::endl;


enum class Color { Red, Green, Blue };
enum class Size { Small, Medium, Large };

struct product
{
  string name;
  Color color;
  Size size;
};


template <typename T> 
struct specification
{
  virtual bool is_satisfied(T* item) = 0;
};

struct color_specification : specification<product>
{
	Color color;
	
	explicit color_specification(const Color color) 
    : color{color} 
  {
  }
	
	bool is_satisfied(product* item) override {
		return item->color == color;
	}
};

template <typename T> 
struct filter
{
  virtual vector<T*> filter_spec(vector<T*> items,specification<T>& spec) = 0;
};

struct better_filter : filter<product>
{
	vector<product*> filter_spec(
		vector<product*> items,
		specification<product>& spec) override
	{
		vector<product*> result;
		for (auto& p : items)
    {
			if (spec.is_satisfied(p))
      {
				result.push_back(p);
      }
    }
		return result;
	}
};

int main()
{
  product apple{ "Apple", Color::Green, Size::Small };
  product tree{ "Tree", Color::Green, Size::Large };
  product house{ "House", Color::Blue, Size::Large };

  vector<product*> all{ &apple, &tree, &house };

  better_filter bf;
  color_specification green(Color::Green);

  auto green_things = bf.filter_spec(all, green);
  for (auto& x : green_things)
    cout << x->name << " is green" << endl;
  return 0;
}