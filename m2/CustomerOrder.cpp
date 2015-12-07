// Milestone 2 - Customer Orders Manager - CustomerOrder Class
// CustomerOrder.cpp
// Rafael Leme de Moraes
// v1.0 07/12/2015

#include "CustomerOrder.h"
#include "Utilities.h"

char CustomerOrder::delimiter = '|';
size_t CustomerOrder::field_width = 0;

CustomerOrder::CustomerOrder(const std::string& record) {
  nOrders = 0;
  order = nullptr;

  size_t next_pos = 0;
  bool more = true;
  Utilities u(field_width);

           name    = u.nextToken(record, next_pos, more);
  if(more) product = u.nextToken(record, next_pos, more);
  // TODO

  field_width = u.getFieldWidth();
}

CustomerOrder::CustomerOrder(const CustomerOrder& customerOrder) {
  // TODO
}

CustomerOrder::CustomerOrder(CustomerOrder&& customerOrder) {
  // TODO
}

CustomerOrder&& CustomerOrder::operator=(CustomerOrder&& customerOrder) {
  // TODO
  return std::move(*this);
}

CustomerOrder::~CustomerOrder() {
  // TODO
}

unsigned int CustomerOrder::noOrders() const {
  // TODO
  return 0;
}

const std::string& CustomerOrder::operator[](unsigned int i) const {
  // TODO
  return name; // wrong
}

void CustomerOrder::fill(Item& item) {
  // TODO
}

void CustomerOrder::remove(Item& item) {
  // TODO
}

bool CustomerOrder::empty() const {
  // TODO
  return false;
}

void CustomerOrder::display(std::ostream& os) const {
  // TODO
}

void CustomerOrder::setDelimiter(const char d) {
  delimiter = d;
}