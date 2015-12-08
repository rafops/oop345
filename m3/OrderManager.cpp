// Milestone 1 - Managers - Order Manager Class
// OrderManager.cpp
// Rafael Leme de Moraes
// v1.0 07/12/2015

#include "OrderManager.h"

void OrderManager::push_back(CustomerOrder&& customerOrder) {
}

CustomerOrder&& OrderManager::extract() {
}

void OrderManager::pop() {
}

bool OrderManager::empty() const {
}

std::vector<CustomerOrder>::iterator OrderManager::begin() {
}

std::vector<CustomerOrder>::iterator OrderManager::end() {
}

const std::vector<CustomerOrder>::const_iterator OrderManager::cbegin() const {
}

const std::vector<CustomerOrder>::const_iterator OrderManager::cend() const {
}

void OrderManager::display(std::ostream& os) const {
}

void validate(const OrderManager& orderManager, const ItemManager& itemManager, std::ostream& os) {
}
