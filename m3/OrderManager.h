#pragma once
// Manager Milestone - OrderManager Interface
// OrderManager.h
// Chris Szalwinski
// v1.1 - 3/12/2015 // added extract, pop, empty (CS)
#include <iostream>
#include <string>

class ItemManager;
class CustomerOrder;

class OrderManager {
  std::vector<CustomerOrder> customerOrders;
public:
  void push_back(CustomerOrder&&);
  CustomerOrder&& extract();
  void pop();
  bool empty() const;
  std::vector<CustomerOrder>::iterator begin();
  std::vector<CustomerOrder>::iterator end();
  const std::vector<CustomerOrder>::const_iterator cbegin() const;
  const std::vector<CustomerOrder>::const_iterator cend() const;
  void display(std::ostream&) const;
};

void validate(const OrderManager&, const ItemManager&, std::ostream&);
