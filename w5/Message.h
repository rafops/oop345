#ifndef W5_MESSAGE_H
#define W5_MESSAGE_H
#include <iostream>
#include "Message.h"

namespace w5 {
  class Message {
  public:
    Message(std::ifstream& in, char c);
    bool empty() const;
    void display(std::ostream&) const;
  };
}

#endif
