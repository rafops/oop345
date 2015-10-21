#include "Message.h"

w5::Message::Message(std::ifstream& in, char c) {
  std::string line;
  getline(in, line, c);
  std::istringstream is(line);
  
  if(user.empty()) {
    is >> user;
  }
  if(reply.empty()) {
    is >> reply;
    if(reply.find('@')==std::string::npos || reply.find('@') != 0) {
      tweet = reply;
      reply.clear();
    }
  }
  if(tweet.empty()) {
    is >> tweet;
  }
  is.clear();  
}  

bool w5::Message::empty() const {
  return user.empty() || tweet.empty();
}

void w5::Message::display(std::ostream& os) const {
  os << "Message" << std::endl;
  os << " User  : " << user << std::endl;
  if(!reply.empty()) {
    os << " Reply : " << reply << std::endl;    
  }
  os << " Tweet : " << tweet << std::endl;
}