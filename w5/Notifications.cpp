#include "Notifications.h"

w5::Notifications::Notifications() {
  messages = nullptr;
  count = 0;
}

w5::Notifications::Notifications(const w5::Notifications& notifications) {
  if(notifications.messages) {
    count = notifications.count;
    messages = new Message*[count];
    for(int i=0; i<count; i++) {
      // not sure if its ok
      messages[i] = notifications.messages[i];
    }
  }
}

w5::Notifications& w5::Notifications::operator=(const w5::Notifications&) {
  return *this;
}

w5::Notifications::Notifications(w5::Notifications&&) {
  
}

w5::Notifications&& w5::Notifications::operator=(w5::Notifications&&) {
  return std::move(*this);
}

w5::Notifications::~Notifications() {
  
}

void w5::Notifications::operator+=(const w5::Message& msg) {
  
}

void w5::Notifications::display(std::ostream& os) const {
  
}