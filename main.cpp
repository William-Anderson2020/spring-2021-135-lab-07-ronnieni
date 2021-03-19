#include <iostream>
#include <fstream>
#include "unindent.h"
#include "indent.h"

int main()
{
  //part A
  std::ifstream input("input.cpp");
  std::string line;

  std::ofstream file("unindented_file.cpp");

  while(getline(input, line)) {
    std::cout << removeLeadingSpaces(line) << "\n";
    file << removeLeadingSpaces(line) << std::endl;
  }

  file.close();


  //part B
  std::cout << countChar("{{{{{{{", '{') << "\n";
  std::cout << countChar("}}}}}}}}}}", '}') << "\n";

  indent_code("unindented_file.cpp");
  return 0;
}
