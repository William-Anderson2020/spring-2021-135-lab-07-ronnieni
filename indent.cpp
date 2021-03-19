#include <iostream>
#include <fstream>

#include "indent.h"


int countChar(std::string line, char c) {
    int counter = 0;
    for (int i = 0; i < line.length(); i++) {
        if (line[i] == c) {
            counter += 1;
        }
    }

    return counter;
}

int indent_code(std::string filename) {

    int tabs = 0;

    std::ifstream input(filename);
    std::string line;

    while(getline(input, line)) {
        std::cout << line << "\n";
        if (countChar(line, '{') == 1) {
            tabs += 1;
        }
        if (countChar(line, '}') == 1) {
            tabs -= 1;
        }
        
        for (int i = 0; i < tabs; i++) {
            std::cout << "\t";
        }

    }

    return 0;
}