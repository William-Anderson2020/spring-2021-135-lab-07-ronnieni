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

    bool singleLineLoop = false;

    while(getline(input, line)) {
        std::cout << line << "\n";
        if (countChar(line, '{') == 1) {
            tabs += 1;
        }
        if (countChar(line, '}') == 1) {
            tabs -= 1;
        }
        if(singleLineLoop == true){ //Checks if an indent for a single line loop is present. If so, removes it.
            tabs -= 1;
            singleLineLoop = false;
        }
        if((line.find("if") <= line.length() || line.find("for") <= line.length()) && line[-1] != '{'){ //Checks line for "if" or "for". If found and final character isn't {, add new indent to accomodate for single line statement.
            tabs += 1;
            singleLineLoop = true; //Marks that a single line loop was just indented
        }
        for (int i = 0; i < tabs; i++) {
            std::cout << "\t";
        }

    }
    return 0;
}