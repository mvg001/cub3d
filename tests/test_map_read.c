#include "libft.h"
#include "map.h"

int main(int ac, char **av) {
    if (ac != 2) {
        ft_putstr_fd("map filename missing", 2);
        return 1;
    }
    t_map *map = map_read(av[1]);
    if (map != NULL) {
        map_print(map);
        map_destroy(&map);
    }
    return 0;
}