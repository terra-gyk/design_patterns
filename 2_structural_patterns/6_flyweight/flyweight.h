#ifndef  __FLYWEIGHT_H__
#define  __FLYWEIGHT_H__

#include <iostream>
#include <string>
#include <memory>
#include <unordered_map>


/**
 * 考虑一个小车，它的共享部分是车轮和引擎，非共享部分是车主和车牌号
 * 那么共享部分可以通过 car_factory 来建造，非共享部分每个car实体单独构造
 */

class car_shared_part
{
public:
  car_shared_part(std::string engine, std::string wheel): engine_(engine),wheel_(wheel){}

  friend std::ostream &operator<<(std::ostream &out,std::shared_ptr<car_shared_part> &car)
  {
    return out << "[ engine: " << car->engine_ << ", wheel: " << car->wheel_ << " ]";
  }

private:
  std::string  engine_;
  std::string  wheel_;
};

class car_unique_part
{
public:
  car_unique_part(std::string owner, std::string number): owner_(owner),number_(number){}

  friend std::ostream &operator<<(std::ostream &out,std::shared_ptr<car_unique_part> car)
  {
    return out << "[ owner: " << car->owner_ << ", number: " << car->number_ << " ]";
  }

private:
  std::string  owner_;
  std::string  number_;
};

class car 
{
public:
  car(std::string owner,std::string number):unique_part_(std::make_shared<car_unique_part>(owner,number)){}

  void set_shared_part(std::shared_ptr<car_shared_part> shared_part)
  {
    shared_part_ = shared_part;
  }

  void display()
  {
    std::cout << unique_part_ << shared_part_ << std::endl;
  }

private:
  std::shared_ptr<car_shared_part>  shared_part_;
  std::shared_ptr<car_unique_part>  unique_part_;
};

class car_factory
{
public:
  std::shared_ptr<car_shared_part> get_car(std::string engine, std::string wheel)
  {
    std::string key = this->get_key(engine,wheel);
    auto iter = car_map_.find(key);
    if(iter == car_map_.end())
    {
      std::cout << "shared part: " << key << " not exist create \n";
      car_map_.emplace(key,std::make_shared<car_shared_part>(engine,wheel));
    }
    else
    {
      std::cout << "shared part: " << key << " exist return \n";
    }
    return car_map_.at(key);
  };

private:
  std::string get_key(std::string owner,std::string number)
  {
    return owner + ":" + number;
  }

  std::unordered_map<std::string, std::shared_ptr<car_shared_part>> car_map_;
};

#endif //__FLYWEIGHT_H__