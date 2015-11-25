#include <iostream>
// #include "Vec.h"
#include "VecTemplate.h"

int main(int argc, char* argv[]) {
  // Vec a;
  // Vec b;
  // 
  // a = b; // use assignment operator
  // 
  // Vec r;
  // Vec s = Vec(7, 9);
  // r = s; // use assignment operator
  // 
  // Vec c = Vec(2, 3);
  // 
  // Vec d = Vec(c); // use copy constructor
  // Vec e = d; // use copy constructor
  // 
  // Vec f = std::move(e); // use move constructor
  // 
  // Vec g;
  // Vec h = Vec(5, 4);
  // g = std::move(h); // use assignment operator
  // 
  // Vec j = Vec(7, 7);
  // Vec k = Vec(std::move(j)); // use move operator

  Vec<int> a;
  Vec<int> b;
  
  a = b; // use assignment operator
  
  Vec<int> r;
  Vec<int> s = Vec<int>(7, 9);
  r = s; // use assignment operator
  
  Vec<int> c = Vec<int>(2, 3);
  
  Vec<int> d = Vec<int>(c); // use copy constructor
  Vec<int> e = d; // use copy constructor
  
  Vec<int> f = std::move(e); // use move constructor
  
  Vec<int> g;
  Vec<int> h = Vec<int>(5, 4);
  g = std::move(h); // use assignment operator
  
  Vec<int> j = Vec<int>(7, 7);
  Vec<int> k = Vec<int>(std::move(j)); // use move operator
  
  return 0;
}