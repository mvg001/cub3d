/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvassall <mvassall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 15:26:21 by mvassall          #+#    #+#             */
/*   Updated: 2025/09/09 14:58:53 by mvassall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
#define MAP_H
#include "vec2d.h"

#define MAP_BUFFER_SIZE 4096

#define WALL_CHAR   '1'
#define EMPTY_CHAR  '.'

typedef struct s_map
{
    char	*no_texture;
    char	*so_texture;
    char	*we_texture;
    char	*ea_texture;
    int    	floor_color;
    int 	ceiling_color;
    int		n_lines;
    int		n_columns;
    char	**plane;        // empty cells: EMPTY_CHAR, wall cells: WALL_CHAR
    int		player_init_y;
    int		player_init_x;
    char	player_init_dir;
}	t_map;

typedef struct s_parser
{
    int state;
    char *cc;
    char *cw;
    char **words;
} t_parser;

// General usage
t_map	*map_create();
void	map_destroy(t_map **map);
int		map_print(t_map *map);
t_map	*map_read(char *filename);
int		map_is_wall_position(t_map *map, double x, double y);
int		map_is_wall(t_map *map, t_vec2d *pos);
int		map_get_cell_char(t_map *map, double x, double y);

// Internal routines
t_map	*map_readfd(int fd);
char	**map_read_all_lines(int fd, int buffer_size);
t_map	*map_parse(char **lines, t_map *map);
int		map_is_empty_line(char *line);
int		map_is_map_line(char *line);
int		map_count_players(t_map *map);
void	map_print_parsing_status(t_parser *p);
void	map_texture_1(t_parser *p);
void	map_texture_2(t_parser *p);
void	map_texture_3(t_parser *p);
void	map_texture_4(t_parser *p);
void	map_texture_5(t_parser *p);
void	map_texture_6(t_parser *p);
void	map_texture_7(t_parser *p);
void	map_texture_8(t_parser *p);
void	map_texture_9(t_parser *p);
int		map_is_texture_line(char *line, t_map *map);
int		map_is_texture_ok(char *filename);
int		map_largest_line(char **lines);
void	map_color1(t_parser *p);
void	map_color2(t_parser *p);
void	map_color3(t_parser *p);
void	map_color4(t_parser *p);
void	map_color5(t_parser *p);
int		map_is_color_line(char *line, t_map *map);
int		map_adjust_lines(t_map *map);
char	*map_trim_right(char *line);
t_map	*map_check(t_map *map);
int		map_check_size(t_map *map);
int		map_set_player(t_map *map);
int		map_walls_check(t_map *map);
#endif