// Milestone 1 - Task Manager - Task Class
// Task.cpp
// Rafael Leme de Moraes
// v1.0 07/12/2015

#include <algorithm> 
#include <functional> 
#include <cctype>
#include <locale>
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

// // trim from start
// static inline std::string &ltrim(std::string &s) {
//   s.erase(s.begin(), std::find_if(s.begin(), s.end(), std::not1(std::ptr_fun<int, int>(std::isspace))));
//   return s;
// }
// 
// // trim from end
// static inline std::string &rtrim(std::string &s) {
//   s.erase(std::find_if(s.rbegin(), s.rend(), std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
//   return s;
// }
// 
// // trim from both ends
// static inline std::string &trim(std::string &s) {
//   return ltrim(rtrim(s));
// }

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
  // size_t space_found;
  // while((space_found = token.find(' ')) != std::string::npos) {
  //   token.erase(space_found);
  // }

  // return trim(token);
  return token;
}

void Utilities::setDelimiter(const char c) {
  delimiter = c;
}

const char Utilities::getDelimiter() {
  return delimiter;
}
