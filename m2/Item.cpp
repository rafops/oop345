// Milestone 2 - Customer Orders Manager - Item Class
// Item.cpp
// Rafael Leme de Moraes
// v1.0 07/12/2015

#include <iomanip>
#include "Item.h"
#include "Utilities.h"

char Item::delimiter = '|';
size_t Item::field_width = 0;

Item::Item(const std::string& record /*= std::string()*/) {
  code = 1;

  size_t next_pos = 0;
  bool more = true;
  Utilities u(field_width);

           name           = u.nextToken(record, next_pos, more);
  if(more) source         = u.nextToken(record, next_pos, more);
  if(more) destination    = u.nextToken(record, next_pos, more);
  if(more) code = std::stoi(u.nextToken(record, next_pos, more));
  if(more) details        = u.nextToken(record, next_pos, more);

  if(details.empty()) details = "no detailed description";

  field_width = u.getFieldWidth();
}

bool Item::empty() const {
  return name.empty();
}

void Item::operator++(int) {
  code++;
}

unsigned int Item::getCode() const {
  return code;
}

const std::string& Item::getName() const {
  return name;
}

const std::string& Item::getSource() const {
  return source;  
}

const std::string& Item::getDestination() const {
  return destination;
}

void Item::display(std::ostream& os, bool full /*= false*/) const {
  /*CPU3456789012[00300] From CPU8901234567To Remove CPU
    0123456789012345678: Central Processing Unit*/
  os << std::left << std::setw(field_width) << name << "[" <<
        std::right << std::setfill('0') << std::setw(CODE_WIDTH) << code << "]";
  if(full) {
    os << " From " << std::left << std::setw(field_width) << source <<
          " To " << std::left << std::setw(field_width) << destination <<
          std::setw(field_width + CODE_WIDTH + 2) << std::right << " : " <<
          details;
  }
  os << std::endl;
}

void Item::setDelimiter(const char d) {
  delimiter = d;
}

size_t Item::getFieldWidth() {
  return field_width;
}