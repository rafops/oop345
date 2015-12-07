// Milestone 2 - Customer Orders Manager - ItemOrder Class
// ItemOrder.cpp
// Rafael Leme de Moraes
// v1.0 07/12/2015

#include <iomanip>
#include "ItemOrder.h"
#include "Utilities.h"

ItemOrder::ItemOrder(const std::string& s /*= std::string()*/) {
  filled = false;
  code = 0;
  name = s;
}

bool ItemOrder::asksFor(const Item& item) const {
  return true; // TODO
}

bool ItemOrder::isFilled() const {
  return filled;
}

void ItemOrder::fill(const unsigned int c) {
  code = c;
  filled = true;
}

void ItemOrder::clear() {
  code = 0;
  filled = false;
}

const std::string& ItemOrder::getName() const {
  return name;
}

void ItemOrder::display(std::ostream& os) const {
  os << " " << (filled ? '+' : '-') << " " << 
     "[" << std::setfill('0') << std::setw(CODE_WIDTH) << code << "] " <<
     name << std::endl;
}