#include <iostream>
#include <cctype>

#include "unindent.h"

std::string removeLeadingSpaces(std::string line) {
    bool whitespace = true;
    std::string new_code = "";
    for (int i = 0; i < line.length(); i++) {
        if (isspace(line[i])) {
            continue;
        } else {
            for (int a = i; a < line.length(); a++) {
                new_code += line[a];
            }
            break;
        }
    }

    return new_code;
}

