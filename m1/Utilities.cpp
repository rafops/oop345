// Milestone 1 - Task Manager - Task Class
// Task.cpp
// Rafael Leme de Moraes
// v1.0 07/12/2015

#include "Utilities.h"

char Utilities::delimiter = '|';

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
  std::string token = str.substr(next_pos);

  size_t delimiter_pos = token.find(delimiter);
  token = delimiter_pos == std::string::npos ?
    token.substr(0, token.find_first_of("\r\n")) : // until end of line
    token.substr(0, delimiter_pos);                // until next delimiter

  if(field_width < token.size()) field_width = token.size();

  next_pos += token.size() + 1;
  more = (next_pos < str.size());

  /* remove white space */
  token.erase(std::remove(token.begin(), token.end(), ' '), token.end());

  return token;
}

void Utilities::setDelimiter(const char c) {
  delimiter = c;
}

const char Utilities::getDelimiter() {
  return delimiter;
}
