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

// Journal 的职责是保存日志
struct Journal
{
  string title;
  vector<string> entries;
  explicit Journal(const std::string& title) : title{title} {}
  void Journal::add(const string& entry){entries.push_back(entry);}
};

// PersistenceManager 的职责是将保存的条目写入文件，持久化存储
struct PersistenceManager
{
  static void save(const Journal& j, const string& filename)
  {
    ofstream ofs(filename);
    for (auto& s: j.entries)
      ofs << s << endl;
  }
};