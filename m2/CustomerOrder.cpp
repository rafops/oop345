// Milestone 2 - Customer Orders Manager - CustomerOrder Class
// CustomerOrder.cpp
// Rafael Leme de Moraes
// v1.0 07/12/2015

#include <vector>
#include <iomanip>
#include "CustomerOrder.h"
#include "ItemOrder.h"
#include "Utilities.h"
#include "Item.h"

char CustomerOrder::delimiter = '|';
size_t CustomerOrder::field_width = 0;

CustomerOrder::CustomerOrder(const std::string& record) {
  nOrders = 0;
  order = nullptr;

  size_t next_pos = 0;
  bool more = true;
  std::vector<std::string> tokens;
  Utilities u(field_width);

           name    = u.nextToken(record, next_pos, more);
  if(more) product = u.nextToken(record, next_pos, more);

  /* extract remaining tokens */
  while(more) tokens.push_back(u.nextToken(record, next_pos, more));
  
  /* create ItemOrders for each remaining token */
  nOrders = tokens.size();
  order = new ItemOrder[nOrders];
  for(std::vector<int>::size_type i=0; i<nOrders; i++) {
    order[i] = ItemOrder(tokens[i]);
  }
  
  field_width = u.getFieldWidth();
}

// Since customer orders are not to be duplicated, 
// the copy constructor should never be called.
CustomerOrder::CustomerOrder(const CustomerOrder& customerOrder) {
  throw "duplication of customer orders are not allowed!";
}

CustomerOrder::CustomerOrder(CustomerOrder&& customerOrder) {
  if(order) delete[] order;
  order = nullptr;
  *this = std::move(customerOrder);
}

CustomerOrder&& CustomerOrder::operator=(CustomerOrder&& customerOrder) {
  if(this!=&customerOrder) {
    if(order) {
      delete[] order;
      order = nullptr;
      nOrders = 0;
    }
    name = customerOrder.name;
    product = customerOrder.product;
    while(nOrders < customerOrder.nOrders) {
      order[nOrders] = customerOrder[nOrders];
      nOrders++;
    }
  }
  return std::move(*this);
}

CustomerOrder::~CustomerOrder() {
  if(order) {
    delete[] order;
    order = nullptr;
    nOrders = 0;
  }
}

unsigned int CustomerOrder::noOrders() const {
  return nOrders;
}

const std::string& CustomerOrder::operator[](unsigned int i) const {
  if(nOrders <= i) throw "index is out of bounds";
  return order[i].getName();
}

void CustomerOrder::fill(Item& item) {
  for(unsigned int i=0; i<nOrders; i++) {
    if(order[i].getName().compare(item.getName())==0) {
      order[i].fill(item.getCode());
      item++;
    }
  }
}

void CustomerOrder::remove(Item& item) {
  for(unsigned int i=0; i<nOrders; i++) {
    if(order[i].getName().compare(item.getName())==0) order[i].clear();
  }
}

bool CustomerOrder::empty() const {
  return name.empty();
}

void CustomerOrder::display(std::ostream& os) const {
  os << std::setw(field_width) << name << " : " <<
        std::setw(field_width) << product << std::endl;
  for(unsigned int i=0; i<nOrders; i++) {
    order[i].display(os);
  }
}

void CustomerOrder::setDelimiter(const char d) {
  delimiter = d;
}