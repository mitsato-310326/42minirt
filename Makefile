# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mitsato <mitsato@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/17 12:44:36 by ainatsug          #+#    #+#              #
#    Updated: 2026/06/23 13:32:21 by keitotak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= miniRT
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -pthread

LIBFT_DIR	= ./libft
LIBFT		= ${LIBFT_DIR}/libft.a
LIBFT_FLAGS	= -L${LIBFT_DIR} -lft

INCLUDE		= -I ./mandatory/includes -I ${LIBFT_DIR}

SRC_DIR		= mandatory/src

OBJ_DIR		= obj

PARSER_DIR	= parser
PRINT_DIR	= printer
HOOK_DIR	= hook
PATTERN_DIR	= pattern

SRC         = \
    ft_mlx.c \
    $(SRC_DIR)/main.c \
    $(SRC_DIR)/$(PARSER_DIR)/init.c \
    $(SRC_DIR)/$(PARSER_DIR)/read.c \
    $(SRC_DIR)/$(PRINT_DIR)/print.c \
    $(SRC_DIR)/$(HOOK_DIR)/hook.c \
    $(SRC_DIR)/$(HOOK_DIR)/camera.c \
    $(SRC_DIR)/$(PATTERN_DIR)/hittable/hittable.c \
    $(SRC_DIR)/$(PATTERN_DIR)/hittable/hittable_utils.c \
    $(SRC_DIR)/$(PATTERN_DIR)/normal.c \
    $(SRC_DIR)/$(PATTERN_DIR)/view_calc.c \
    $(SRC_DIR)/utils/ray_utils/ray_func.c \
    $(SRC_DIR)/utils/vec_utils/vec_calc.c \
    $(SRC_DIR)/utils/vec_utils/vec_func2.c \
    $(SRC_DIR)/utils/ft_weekend.c \
    $(SRC_DIR)/material/lambertian.c \
    $(SRC_DIR)/material/metal.c


OBJ 		= $(SRC:${SRC_DIR}/%.c=$(OBJ_DIR)/%.o)
MLX_LIB = mlx/
MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11 -lm

.PHONY: all
all: $(NAME)

debug: RULE=debug
debug: CC=gcc
debug: CFLAGS=-g3 -Wall -Wextra -Werror -pthread
debug: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	@make -C $(MLX_LIB)
	$(CC) $(CFLAGS) ${INCLUDE} $(OBJ) $(LIBFT_FLAGS) $(MLX_FLAGS) -o $(NAME)

$(OBJ_DIR)/%.o: mandatory/src/%.c mlx/mlx.h
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) ${INCLUDE} -c $< -o $@

mlx/mlx.h:
	git clone https://github.com/42Paris/minilibx-linux.git mlx

$(LIBFT):
	@-$(MAKE) -C $(LIBFT_DIR)

.PHONY: clean
clean:
	@rm -rf $(OBJ_DIR)
	@-$(MAKE) -C $(MLX_LIB) clean
	@-$(MAKE) -C $(LIBFT_DIR) clean

.PHONY: fclean
fclean: clean
	@rm -f $(NAME)
	@-$(MAKE) -C $(MLX_LIB) fclean
	@-$(MAKE) -C $(LIBFT_DIR) fclean

.PHONY: re
re: fclean all
