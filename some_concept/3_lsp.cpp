/**
 * 里氏替换原则
 * 子类对象（subtype）应该能够替换其父类对象（supertype）被使用，而不破坏程序的正确性。
 * 
 * 反直觉。期望所有子类行为是一致的，但如果不一致可能需要文档记录，或者在代码跑失败后涨此知识；
 * 不可读。如果子类行为不一致，可能需要不同的逻辑分支来适配不同的行为，徒增代码复杂度；
 * 不可用。可能出错的地方终将会出错。
 * 
 * 如果父类A和子类B之间的关系违反了里氏替换原则，那么A和B就不适合设计为继承关系。我们就要重新设计二者之间的关系。设计方案有两种，需要根据具体情况进行选择：、
 * 1. 创建一个新的抽象类或者接口，作为两个具体类的基类。将具体类A和B的共同行为转移到C中，从而解决A和B行为不一致的问题。
 * 2. 将B到A的继承关系改为委托关系。具体参考组合/聚合复用原则。
 */

#include <iostream>

class Rectangle {
public:
  virtual void setWidth(int w) {
    width = w;
  }
  
  virtual void setHeight(int h) {
    height = h;
  }
  
  int getWidth() const {
    return width;
  }
  
  int getHeight() const {
    return height;
  }
  
  int area() const {
    return width * height;
  }
  
protected:
  int width;
  int height;
};

class Square : public Rectangle {
public:
  void setWidth(int w) override {
    width = height = w; // Square的宽和高是相等的
  }
  
  void setHeight(int h) override {
    width = height = h; // Square的宽和高是相等的
  }
};

int main() {
  Rectangle* r = new Rectangle();
  r->setWidth(5);
  r->setHeight(10);
  std::cout << "Rectangle area: " << r->area() << std::endl;
  
  // 使用Square替换Rectangle
  r = new Square();
  r->setWidth(5); // 设置宽度
  // 这里违反了里氏替换原则，因为setWidth实际上也改变了高度，
  std::cout << "Square area (should be 50, but...): " << r->area() << std::endl;
  
  return 0;
}
