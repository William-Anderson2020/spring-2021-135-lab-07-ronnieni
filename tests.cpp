#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "unindent.h"
#include "indent.h"

// add your tests here
TEST_CASE("remove leading spaces") {
    CHECK(removeLeadingSpaces("       int x = 1;  ") == "int x = 1;  ");
    CHECK(removeLeadingSpaces("           // Hi, I'm a program") == "// Hi, I'm a program");
    CHECK(removeLeadingSpaces("    for(int i = 0; i < 10; i++) {") == "for(int i = 0; i < 10; i++) {");
    CHECK(removeLeadingSpaces("          cout << endl;") == "cout << endl;");
}

TEST_CASE("countChar") {
    CHECK(countChar("{{{{{{{", '{') == 7);
    CHECK(countChar("{}{}{}{}", '}') == 4);
    CHECK(countChar("}}}", '{') == 0);
    CHECK(countChar("if (true) {", '{') == 1);
}