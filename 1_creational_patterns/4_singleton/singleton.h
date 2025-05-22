#ifndef __SINGETON_H__
#define __SINGETON_H__

#include <iostream>
#include <atomic>
#include <mutex>

class static_cpp11 {
protected:
  static_cpp11() {}

public:
  static_cpp11(static_cpp11 const&) = delete;
  static_cpp11(static_cpp11&&) = delete;
  static_cpp11& operator=(static_cpp11 const&) = delete;
  static_cpp11& operator=(static_cpp11&&) = delete;

  static static_cpp11& get_instance() 
  {
    // 这种写法在c++11是线程安全的
    static static_cpp11 database;
    return database;
  }

  void print(){ std::cout<< "this is static_cpp11 singleton\n"; }

};

class double_check {
private:
  static double_check* instance;
  static std::mutex mutex;

  double_check() {}
  double_check(const double_check&) = delete;
  double_check(double_check&&) = delete;
  double_check& operator=(const double_check&) = delete;
  double_check& operator=(double_check&&) = delete;

public:
  static double_check* get_instance() 
  {
    // 第一次检查
    if (instance == nullptr) 
    {
      std::lock_guard<std::mutex> lock(mutex);
      // 第二次检查
      if (instance == nullptr) 
      {
        instance = new double_check();
      }
    }
    return instance;
  }

  void print(){ std::cout<< "this is double_check singleton\n"; }

  static void destroy_instrance() 
  {
    delete instance;
    instance = nullptr;
  }
};

// 静态成员应该放在 .cpp 文件中初始化，这里只是示例代码，不做强制要求
double_check* double_check::instance = nullptr;
std::mutex double_check::mutex;

#endif //__SINGETON_H__