#ifndef __BRIDGE_H__
#define __BRIDGE_H__

#include <iostream>
#include <string>
#include <memory>

class color
{
public:
  virtual std::string get_color() = 0;
};

class color_blue : public color
{
public:
  std::string get_color() override
  {
    return "color blue";
  }
};

class color_red : public color
{
public:
  std::string get_color() override
  {
    return "color red";
  }
};

class shape
{
public:
  shape(std::shared_ptr<color> color):color_impl_(color){}
  virtual std::string smear_color() = 0; 

protected:
  std::shared_ptr<color>   color_impl_;
};

class shape_circle : public shape
{
public:
  shape_circle(std::shared_ptr<color> color) : shape(color){}
  std::string smear_color() override
  {
    return "shape circle, " + color_impl_->get_color(); 
  }
};

class shape_rectangle : public shape
{
public:
  shape_rectangle(std::shared_ptr<color> color) : shape(color){}
  std::string smear_color() override
  {
    return "shape rectangle, " + color_impl_->get_color(); 
  }
};

#endif // __BRIDGE_H__