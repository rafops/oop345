// Milestone 3 - Managers - Item Manager Class
// ItemManager.cpp
// Rafael Leme de Moraes
// v1.0 07/12/2015

#include "Item.h"
#include "ItemManager.h"

void ItemManager::push_back(Item&& item) {
  items.push_back(std::move(item));
}

std::vector<Item>::iterator ItemManager::begin() {
  return items.begin();
}

std::vector<Item>::iterator ItemManager::end() {
  return items.end();
}

const std::vector<Item>::const_iterator ItemManager::cbegin() const {
  return items.cbegin();
}

const std::vector<Item>::const_iterator ItemManager::cend() const {
  return items.cend();
}

void ItemManager::display(std::ostream& os, bool full /*= false*/) const {
  for(auto& i: items) i.display(os, full);
}
