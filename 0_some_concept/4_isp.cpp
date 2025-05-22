/**
 * 接口隔离原则
 * 客户端不应该被迫依赖于它们不使用的接口。
 */

#include <string>
#include <vector>

using std::string;
using std::vector;


class document;

// 从设计上来说，不一定所有的机器都有如下的三个功能
struct i_machine
{
  virtual void print(vector<document*> docs) = 0;
  virtual void fax(vector<document*> docs) = 0;
  virtual void scan(vector<document*> docs) = 0;
};

// 因此可以拆分成如下
struct i_printer
{
  virtual void print(vector<document*> docs) = 0;
};

struct i_scanner
{
  virtual void scan(vector<document*> docs) = 0;
};


struct i_fax 
{  
	virtual void fax(vector<document*> docs) = 0;
};

// 通过继承来获取需要的方法
struct machine : i_printer,i_scanner
{
	i_printer& printer;
	i_scanner& scanner;
	
	machine(i_printer& printer, i_scanner& scanner)  
		: printer{printer},
		  scanner{scanner} 
	{
	}
	
	void print(vector<document*> docs) override
	{
		printer.print(docs);
	}
	
	void scan(vector<document*> docs) override
	{
		scanner.scan(docs);
	}
};