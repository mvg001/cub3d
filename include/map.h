/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvassall <mvassall@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 15:26:21 by mvassall          #+#    #+#             */
/*   Updated: 2025/09/07 16:48:21 by mvassall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
#define MAP_H

#define MAP_BUFFER_SIZE 4096

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
    char	**plane;
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

void	*map_create();
void	map_destroy(t_map **map);
int		map_print(t_map *map);
char	**map_read_all_lines(int fd, int buffer_size);
t_map	*map_readfd(int fd);
t_map	*map_read(char *filename);
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
#endif