#include <stdio.h>
#include "map.h"

void test(char *line, int expected) {
    printf("\n=======test line '%s'\n", line);
    expected = expected != 0;
    int result = map_is_map_line(line);
    printf("%s: %d\n", 
        result == expected ? "OK " : "NOK", result);
}

int main(void) {
    test("111111", 1);
    test("   111111", 1);
    test("100101", 1);
    test("1100N1", 1);
    test("110S01", 1);
    test("110E01", 1);
    test("110W01", 1);
    test("111 111", 1);
    test("  111 111  ", 1);
    test("  101 101  ", 1);
    return 0;
}