// Milestone 2 - Customer Orders Manager - ItemOrder Class
// ItemOrder.cpp
// Rafael Leme de Moraes
// v1.0 07/12/2015

#include "ItemOrder.h"

ItemOrder::ItemOrder(const std::string& record /*= std::string()*/) {
  filled = false;
  code = 0;
  // TODO
}

bool ItemOrder::asksFor(const Item& item) const {
  return false; // TODO
}

bool ItemOrder::isFilled() const {
  return false; // TODO
}

void ItemOrder::fill(const unsigned int c) {
  // TODO
}

void ItemOrder::clear() {
  // TODO
}

const std::string& ItemOrder::getName() const {
  return name;
}

void ItemOrder::display(std::ostream& os) const {
  // TODO
}