#include <iostream>
#include "CString.h"
#include "process.h"

using namespace w1;

void process(const char *str)
{
  CString cStr(str);
  std::cout << cStr << std::endl;
}
