#include <iostream>
#include "Vec.h"

Vec::Vec(int x, int y) {
  _x = x;
  _y = y;
  std::cout << "born with x=" << _x << "and y=" << _y << std::endl;
}

Vec::Vec() {
  _x = 0;
  _y = 0;
  std::cout << "born with zeroes" << std::endl;
}

Vec::~Vec() {
  std::cout << "died with x=" << _x << "and y=" << _y << std::endl;
}

Vec::Vec(const Vec& v) {
  if(this != &v) {
    _x = v._x;
    _y = v._y;
  }
  std::cout << "copied (using copy constructor) with x=" << _x << "and y=" << _y << std::endl;
}

Vec& Vec::operator=(const Vec& v) {
  if(this != &v) {
    _x = v._x;
    _y = v._y;
  }
  std::cout << "copied (using assignment operator) with x=" << _x << "and y=" << _y << std::endl;
}

Vec::Vec(const Vec&& v) {
  _x = v._x;
  // v._x = -5;
  _y = v._y;
  // v._y = -5;
  std::cout << "moved (using move constructor) with x=" << _x << "and y=" << _y << std::endl;
}

Vec& Vec::operator=(const Vec&& v) {
  if(this != &v) {
    _x = v._x;
    _y = v._y;
  }
  std::cout << "moved (using assignment operator) with x=" << _x << "and y=" << _y << std::endl;
  return *this;
}
