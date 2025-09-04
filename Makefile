# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvassall <mvassall@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/11 11:05:02 by user1             #+#    #+#              #
#    Updated: 2025/09/04 15:49:33 by mvassall         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC := cc
CFLAGS := -Wall -Werror -Wextra -g3 -fsanitize=address -Iinclude -Ilibft
#CFLAGS := -Wall -Werror -Wextra -pthread -g3 -fsanitize=thread
#CFLAGS := -Wall -Werror -Wextra -g3
RM := /bin/rm -f
SRC_DIRS := ./src
BUILD_DIR := ./build

SRCS := $(shell find $(SRC_DIRS) -name '*.c')

OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)

NAME = cub3d

.PHONY: all clean fclean re

all: $(NAME)

show:
	echo $(OBJS)

$(NAME): $(OBJS) libft/libft.a
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -Llibft -lft

$(OBJS): include/map.h include/player.h include/vec2d.h libft/libft.h

libft/libft.a:
	cd libft && $(MAKE) all

$(BUILD_DIR)/%.c.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I./include -o $@ -c $<

clean:
	$(RM) -r $(BUILD_DIR)

fclean: clean
	$(RM) $(NAME) 

re: fclean all
