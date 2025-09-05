#include <stdio.h>
#include "map.h"

void test(char *line, t_map *map, int expected) {
    printf("\n=======test line '%s'\n", line);
    expected = expected != 0;
    map->ceiling_color = -1;
    map->floor_color = -1;
    int result = is_color_line(line, map);
    printf("%s: %d\n", 
        result == expected ? "OK " : "NOK", result);
    if (result) {
        printf("C: %08x\n", map->ceiling_color);
        printf("F: %08x\n", map->floor_color);
    }
}

int main(void) {
    t_map *m = map_create();
    if (m == NULL)
        return 1;
    test("F 255,0,0", m, 1);
    test("C   0,   0,0    ", m, 1);
    test("C 0 , 255 , 0 ", m, 1);
    test("C 0 , 0 , 255 ", m, 1);
    test("A 0,255,0", m, 0);
    test("C 0 ,255, 0,0 ", m, 0);
    test("C 0,2555,0", m, 0);
    test("C 0,,0", m, 0);
    test("C 0", m, 0);
    test("C 0", m, 0);
    test("C ,", m, 0);

    map_destroy(&m);
    return 0;
}