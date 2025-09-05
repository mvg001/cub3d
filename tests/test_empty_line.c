#include <stdio.h>
#include "map.h"

void test(char *line, int expected) {
    expected = expected != 0;
    int result = is_empty_line(line);
    printf("%s: %d: '%s'\n", 
        result == expected ? "OK " : "NOK", result, line);
}

int main(void) {
    test("", 1);
    test("   ", 1);
    test("\t\t", 1);
    test(" \t \t ", 1);
    test(NULL, 1);
    test("NO ./path_to_the_north_texture", 0);
    test("F 220,100,0", 0);
    test("          1111111111111111111111111", 0);
    test("11111111 1111111 111111111111", 0);
    test("11000001110101011111011110N0111", 0);
    return 0;
}