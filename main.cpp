#include <iostream>
#include <fstream>
#include "unindent.h"

int main()
{
  //part A
  std::ifstream input("input.cpp");
  std::string line;

  while(getline(input, line)) {
    std::cout << removeLeadingSpaces(line) << "\n";
  }

  //part B
  
  return 0;
}
