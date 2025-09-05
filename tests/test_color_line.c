#include <stdio.h>
#include "map.h"

void test(char *line, t_map *map, int expected) {
    expected = expected != 0;
    map->ceiling_color = -1;
    map->floor_color = -1;
    int result = is_color_line(line, map);
    printf("%s: %d: '%s'\n", 
        result == expected ? "OK " : "NOK", result, line);
    if (result) {
        printf("C: %x\n", map->ceiling_color);
        printf("F: %x\n", map->floor_color);
    }
}

int main(void) {
    t_map *m = map_create();
    if (m == NULL)
        return 1;
    test("F 255,0,0", m, 1);
    test("F 0,0,0", m, 1);
    test("C 0,255,0", m, 1);
    test("C 0,0,255", m, 1);
    test("A 0,255,0", m, 0);
    test("C 0,255,0,0", m, 0);
    test("C 0,2555,0", m, 0);
    test("C 0,,0", m, 0);
    test("C 0", m, 0);
    test("C 0", m, 0);
    test("C ,", m, 0);
    map_destroy(&m);
    return 0;
}