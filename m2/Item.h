#pragma once
// CustomerOrder Milestone - Item Interface
// Item.h
// Chris Szalwinski
// v1.0 - 9/11/2015
#include <iostream>
#include <string>

class Item {
  std::string name;
  std::string source;
  std::string destination;
  std::string details;
  unsigned int code;
  static char delimiter;
  static size_t field_width;
public:
  Item(const std::string& = std::string());
  // returns true if the current object is in a safe empty state
  bool empty() const;
  // increments the code to be printed on the next insertion by 1
  void operator++(int);
  // returns a copy of the code to be printed on the next insertion
  unsigned int getCode() const;
  // returns a copy of the string that contains the name of the item
  const std::string& getName() const;
  // returns a copy of the string that contains the name of the task that
  // inserts the item into a product
  const std::string& getSource() const;
  // returns a copy of the string that contains the name of the task that
  // extracts the item from a product
  const std::string& getDestination() const;
  // inserts into the referenced ostream object the name of the item
  // and its current code
  void display(std::ostream&, bool = false) const;
  // reset the delimiter for all Itemobjects to the character received
  static void setDelimiter(const char);
  // returns the field_width for all Item objects processed
  static size_t getFieldWidth();
};