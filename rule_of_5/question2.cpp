#include <iostream>
#include <cstring>

class X {
  size_t size_;
  char *buffer_;
public:
  X() : size_(0), buffer_(nullptr) {
    std::cout << "default constructor" << std::endl;
  }
  X(size_t size) {
    std::cout << "overloaded constructor size=" << size << std::endl;
    buffer_ = new char[size];
    size_ = size;
  }
  void print() {
    std::cout << "print size=" << size_ << std::endl;
  }
  /* rule of five */
  X(const X& x) : X() {
    std::cout << "copy constructor size=" << x.size_ << std::endl;
    buffer_ = new char[x.size_];
    if(buffer_) {
      size_ = x.size_;
      strncpy(buffer_, x.buffer_, size_);
    }
  }
  X& operator=(const X& x) { // copy assignment operator
    std::cout << "copy assignment operator size=" << x.size_ << std::endl;
    if(this != &x) {
      if(buffer_) {
        delete[] buffer_;
        buffer_ = nullptr;
        size_ = 0;
      }
      // *this = x;
      buffer_ = new char[x.size_];
      if(buffer_) {
        size_ = x.size_;
        strncpy(buffer_, x.buffer_, size_);
      }
    }
    return *this;
  }
  X(X&& x) : X() { // move constructor
    std::cout << "move construtor size=" << x.size_ << std::endl;;
    std::swap(buffer_, x.buffer_);
    std::swap(size_, x.size_);
  }
  X& operator=(X&& x) { // move assignment operator
    std::cout << "move assignment operator size=" << x.size_ << std::endl;
    if(this != &x) {
      if(buffer_) delete[] buffer_;
      buffer_ = x.buffer_;
      size_ = x.size_;
      x.buffer_ = nullptr;
      x.size_ = 0;
    }
    return *this;
  }
  // no difference?
  // X&& operator=(X&& x) { // move assignment operator
  //   std::cout << "move assignment operator size=" << x.size_ << std::endl;
  //   if(this != &x) {
  //     if(buffer_) delete[] buffer_;
  //     buffer_ = x.buffer_;
  //     size_ = x.size_;
  //     x.buffer_ = nullptr;
  //     x.size_ = 0;
  //   }
  //   return std::move(*this);
  // }
  ~X() { // destructor
    std::cout << "destructor size=" << size_ << std::endl;
    if(buffer_) delete[] buffer_;
  }
};

int main(int argc, char* argv[]) {
  
  X* xPtr = new X;
  xPtr->print();          // 0

  X xx(10000);
  xx.print();             // 10000

  X xxx(*xPtr);           // X(const X&)
  xxx.print();            // 0
  xPtr->print();          // 0

  *xPtr = xxx;            // X& operator=(const X&)
  xPtr->print();          // 0
  xxx.print();            // 0

  xxx = xx;               // X& operator=(const X&)
  xxx.print();            // 10000
  xx.print();             // 10000

  X xxxx(std::move(xx));  // X(X&&)
  xxxx.print();           // 10000
  xx.print();             // 0

  xx = std::move(xxxx);   // X& operator=(X&&)
  xx.print();             // 10000
  xxxx.print();           // 0

  delete xPtr;            // ~X()
  
  return 0;               // ~X()
                          // ~X()
                          // ~X()
}

// clang++ -std=c++11 -o question2 question2.cpp && ./question2