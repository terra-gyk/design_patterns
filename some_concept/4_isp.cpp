/**
 * 接口隔离原则
 * 客户端不应该被迫依赖于它们不使用的接口。
 */

#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;
using std::cout;
using std::endl;

class Document;

// 从设计上来说，不一定所有的机器都有如下的三个功能
struct IMachine
{
  virtual void print(vector<Document*> docs) = 0;
  virtual void fax(vector<Document*> docs) = 0;
  virtual void scan(vector<Document*> docs) = 0;
};

// 因此可以拆分成如下
struct IPrinter
{
  virtual void print(vector<Document*> docs) = 0;
};

struct IScanner
{
  virtual void scan(vector<Document*> docs) = 0;
};

// 通过继承来获取需要的方法
struct IMachine : IPrinter, IScanner /* IFax and so on */
{  
};

struct Machine : IMachine
{
	IPrinter& printer;
	IScanner& scanner;
	
	Machine(IPrinter& printer, IScanner& scanner)
		: printer{printer},
		  scanner{scanner}
	{
	}
	
	void print(vector<Document*> docs) override
	{
		printer.print(docs);
	}
	
	void scan(vector<Document*> docs) override
	{
		scanner.scan(docs);
	}
};