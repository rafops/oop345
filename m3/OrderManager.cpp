// Milestone 3 - Managers - Order Manager Class
// OrderManager.cpp
// Rafael Leme de Moraes
// v1.0 07/12/2015

#include <algorithm>
#include "CustomerOrder.h";
#include "ItemManager.h";
#include "OrderManager.h"

void OrderManager::push_back(CustomerOrder&& customerOrder) {
  customerOrders.push_back(std::move(customerOrder));
}

CustomerOrder&& OrderManager::extract() {
  std::move(customerOrders.pop_back());
}

void OrderManager::pop() {
  customerOrders.pop();
}

bool OrderManager::empty() const {
  return customerOrders.empty();
}

std::vector<CustomerOrder>::iterator OrderManager::begin() {
  return customerOrders.begin();
}

std::vector<CustomerOrder>::iterator OrderManager::end() {
  return customerOrders.end();
}

const std::vector<CustomerOrder>::const_iterator OrderManager::cbegin() const {
  return customerOrders.cbegin();
}

const std::vector<CustomerOrder>::const_iterator OrderManager::cend() const {
  return customerOrders.cend();
}

void OrderManager::display(std::ostream& os) const {
  for(auto& i: customerOrders) i.display(os);
}

void validate(const OrderManager& orderManager, const ItemManager& itemManager, std::ostream& os) {
  for(auto i=orderManager.cbegin(); i!=orderManager.cend(); ++i) {
    const auto& customerOrder = *i;
    for(unsigned int j=0; j<customerOrder.noOrders(); ++j) {
      auto hasItem = [&](const Item& item) {
        return customerOrder[j]==item.getName();
      };
      if(std::find_if(itemManager.cbegin(), itemManager.cend(), hasItem)==itemManager.cend()) {
        os << customerOrder[j] << " is unavailable" << std::endl;
      }
    }
  }
}
