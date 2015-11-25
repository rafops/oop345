#include <iostream>

template<typename T>
void print(const T& lvalue) {
  std::cout << lvalue << " L-Value" << std::endl;
}

template<typename T>
void print(const T&& rvalue) {
  std::cout << rvalue << " R-Value" << std::endl;
}

int main(int argc, char* argv[]) {
  char broiled = 'X';
  float icecream = 42;
  double trouble = 665.;
  
  print(broiled);   // X L-Value
  print(icecream);  // 42 L-Value
  print(trouble);   // 665 L-Value
  print(9);         // 9 R-Value
  print(2+10.6);    // 12.6 R-Value
  print(trouble+1); // 666 R-Value
  
  return 0;
}

// clang++ -std=c++11 -o question1 question1.cpp && ./question1