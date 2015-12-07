#pragma once
// CustomerOrder Milestone - CustomerOrder Interface
// CustomerOrder.h
// Chris Szalwinski
// v1.0 9/11/2015
#include <iostream>
#include <string>

class Item;
class ItemOrder;

class CustomerOrder {
  std::string name;
  std::string product;
  ItemOrder* order;
  unsigned int nOrders;
  static char delimiter;
  static size_t field_width;
public:
  CustomerOrder(const std::string&);
  CustomerOrder(const CustomerOrder&);
  CustomerOrder& operator=(const CustomerOrder&) = delete; 
  CustomerOrder(CustomerOrder&&);
  CustomerOrder&& operator=(CustomerOrder&&);
  ~CustomerOrder();
  // returns the number of item orders in the current object
  unsigned int noOrders() const;
  // returns a reference to the name of item order i;
  // reports an exception if the index is out of bounds
  const std::string& operator[](unsigned int i) const;
  // searches through the ordered items and fills those orders identified by
  // the name of the Item received if any have not been filled.  This function
  // increments the Item object's code for each order filled
  void fill(Item&);
  // searches through the items ordered and removes those items identified by
  // the name of the Item received if the corresponding order has been filled.
  // This function does not alter the Item object's code
  void remove(Item&);
  // returns true if the current object is in a safe empty state
  bool empty() const;
  // inserts into the referenced ostream object a description of
  // the customer order.
  void display(std::ostream&) const;
  // resets the delimiter for extracting tokens to the character received
  static void setDelimiter(const char);
};
