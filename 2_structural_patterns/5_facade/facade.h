#ifndef __FACADE_H__
#define __FACADE_H__

#include <iostream>
#include <string>
#include <memory>

class cicle 
{
public:
  void draw()
  {
    std::cout<< "cicle draw. \n";
  }
};

class rectangle 
{
public:
  void draw()
  {
    std::cout<< "rectangle draw. \n";
  }
};


class shape_maker
{
public:
  void draw_cicle()
  {
    cicle_->draw();
  }

  void draw_rectangle()
  {
    rectangle_->draw();
  }

  void draw_all()
  {
    cicle_->draw();
    rectangle_->draw();
  }

private:
  std::unique_ptr<cicle>  cicle_ = std::make_unique<cicle>();
  std::unique_ptr<rectangle>  rectangle_ = std::make_unique<rectangle>();
};

#endif // __FACADE_H__