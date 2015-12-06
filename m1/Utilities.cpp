// Milestone 1 - Task Manager - Task Class
// Task.cpp
// Rafael Leme de Moraes
// v1.0 07/12/2015

#include "Utilities.h"

char Utilities::delimiter = '\0';

Utilities::Utilities(size_t minimum_field_width /*= 1u*/) {
  field_width = minimum_field_width;
}

void Utilities::setFieldWidth(size_t fw) {
  field_width = fw;
}

size_t Utilities::getFieldWidth() const {
  return field_width;
}

const std::string Utilities::nextToken(const std::string& str, size_t& next_pos, bool& more) {
  std::string token;

  while(true) {
    if(str[next_pos] == delimiter) break;
    if(str.size() <= next_pos) {
      more = false;
      break;
    }
    token += str[next_pos++];
  }

  if(token.size() > field_width) field_width = token.size();

  return token;
}

void Utilities::setDelimiter(const char c) {
  delimiter = c;
}

const char Utilities::getDelimiter() {
  return delimiter;
}
