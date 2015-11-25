#pragma once

class Vec {
  int _x;
  int _y;
public:
  Vec(int x, int y);
  /* rule of three */
  Vec();
  Vec(const Vec& v); // copy constructor
  ~Vec();
  Vec& operator=(const Vec& v);
  /* rule of five */
  Vec(const Vec&& v);
  Vec& operator=(const Vec&& v);
};