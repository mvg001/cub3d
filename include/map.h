/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvassall <mvassall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 15:26:21 by mvassall          #+#    #+#             */
/*   Updated: 2025/09/03 13:12:35 by mvassall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
#define MAP_H

#include <stdint.h>

#define MAP_BUFFER_SIZE 4096

typedef struct s_map
{
    char		*no_texture;
    char		*so_texture;
    char		*we_texture;
    char		*ea_texture;
    uint32_t	floor_color;
    uint32_t	ceiling_color;
    int			n_lines;
    int			n_columns;
    char        **plane;
}	t_map;

typedef struct s_parser
{
    int state;
    char *cc;
    char *cw;
    char **words;
} t_parser;

void	map_destroy(t_map **map);
char	**read_all_lines(int fd, int buffer_size);
t_map	*map_readfd(int fd);
t_map	*map_read(char *filename);
t_map	*map_parse(char **lines, t_map *map);
int		is_empty_line(char *line);
int		is_map_line(char *line);

void	map_texture_1(t_parser *p);
void	map_texture_2(t_parser *p);
void	map_texture_3(t_parser *p);
void	map_texture_4(t_parser *p);
void	map_texture_5(t_parser *p);
#endif