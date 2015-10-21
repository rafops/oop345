#include "Notifications.h"

w5::Notifications::Notifications() {
  
}

w5::Notifications::Notifications(const w5::Notifications&) {
  
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