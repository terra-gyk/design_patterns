/**
 * 单一职责原则 Single Responsibility
 * 每个类只有一个责任
 */

#include <vector>
#include <string>
#include <fstream>

using std::string;
using std::vector;
using std::ofstream;
using std::endl;

// journal 的职责是保存日志
struct journal
{
  string title;
  vector<string> entries;
  explicit journal(const std::string& title) 
    : title{title} 
  {
  }
  
  void add(const string& entry){ entries.push_back(entry); }
};

// PersistenceManager 的职责是将保存的条目写入文件，持久化存储
struct persistence_manager
{
  static void save(const journal& j, const string& filename)
  {
    ofstream ofs(filename);
    for (auto& s: j.entries)
    {
      ofs << s << endl;
    }
  }
};