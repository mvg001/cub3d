#include <stdio.h>
#include "map.h"

void test(char *line, int expected) {
    t_map *m = map_create();
    printf("\n=======test line '%s'\n", line);
    expected = expected != 0;
    int result = is_texture_line(line, m);
    printf("%s: %d\n", 
        result == expected ? "OK " : "NOK", result);
    if (result) {
        printf("NO: '%s'\n", m->no_texture);
        printf("SO: '%s'\n", m->so_texture);
        printf("WE: '%s'\n", m->we_texture);
        printf("EA: '%s'\n", m->ea_texture);
    }
    map_destroy(&m);
}

int main(void) {
    t_map *m = map_create();
    if (m == NULL) return -1;
    // test("NO ./path_to_the_north_texture", 1);
    // test("NO     ./path_to_the_north_texture    ", 1);
    // test("NO \"./path_to_the_north_texture\"", 1);

    map_destroy(&m);
    return 0;
}