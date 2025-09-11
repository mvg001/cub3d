# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvassall <mvassall@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/11 11:05:02 by user1             #+#    #+#              #
#    Updated: 2025/09/11 16:33:10 by mvassall         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME   := cub3d.exe
CC     := cc
CFLAGS := -Wall -Werror -Wextra -g3 -fsanitize=address -Ofast
#CFLAGS := -Wall -Werror -Wextra -pthread -g3 -fsanitize=thread
#CFLAGS := -Wall -Werror -Wextra -g3
RM := /bin/rm -f

LIBMLX := ./lib/MLX42
LIBFT  := ./lib/libft
HEADERS := -I ./include -I $(LIBFT) -I $(LIBMLX)/include
SRC_DIR := ./src
INC_DIR := ./include
BUILD_DIR := ./build

SRCS := $(shell find $(SRC_DIR) -name '*.c')
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(LIBFT)/libft.a $(LIBMLX)/build/libmlx42.a $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L$(LIBFT) -lft \
		-L $(LIBMLX)/build/ -l mlx42 -lm -ldl -lglfw -pthread

$(OBJS): $(LIBFT)/libft.h $(LIBMLX)/include/MLX42/MLX42.h \
	$(shell find $(INC_DIR) -name '*.h')

$(LIBFT)/libft.a:
	cd libft && $(MAKE) all

$(LIBMLX)/build/libmlx42.a:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

$(BUILD_DIR)/%.c.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(HEADERS) -o $@ -c $<

clean:
	$(RM) -rf $(BUILD_DIR)
	$(RM) -rf $(LIBMLX)/build

fclean: clean
	$(RM) $(NAME) 

re: fclean all
