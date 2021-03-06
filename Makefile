# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/08 00:23:17 by hesayah           #+#    #+#              #
#    Updated: 2021/08/05 19:32:26 by hesayah          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

NAME_BONUS = so_Bonus

INCLUDE = So_long.h libs/libft/libft.h libs/gnl/get_next_line.h

SRCS =	libs/gnl/get_next_line_utils.c \
		libs/gnl/get_next_line.c \
		srcs/so_long.c \
		srcs/init.c \
		srcs/pars_brain.c \
		srcs/pars_map.c \
		srcs/get_xpm.c \
		srcs/key.c \
		srcs/drawing.c \
		srcs/drawing_utils.c \
		srcs/exit.c

OBJ = $(SRCS:.c=.o)

SRCS_BONUS =	libs/gnl/get_next_line_utils.c \
				libs/gnl/get_next_line.c \
				srcs_bonus/so_long.c \
				srcs_bonus/init.c \
				srcs_bonus/pars_brain.c \
				srcs_bonus/pars_map.c \
				srcs_bonus/get_xpm.c \
				srcs_bonus/key.c \
				srcs_bonus/drawing.c \
				srcs_bonus/drawing_utils.c \
				srcs_bonus/exit.c

OBJ_BONUS = $(SRCS_BONUS:.c=.o)

LIBFT_PATH = libs/libft

MLX_PATH = libs/mlx

LIB = libs/libft/libft.a libs/mlx/libmlx.a

GCC = gcc

FLAGS = -Wall -Wextra -Werror -std=c11 -O3 -g3 -ggdb3 #-fsanitize=address 

MLX = -Llibs/mlx -lmlx -lXext -lX11 -lbsd -lm

all: $(NAME)
$(NAME):${OBJ}
	@echo "\033[32m[Compile Lib...]"
	@$(MAKE) -C $ $(LIBFT_PATH)
	@echo "\033[32m[Compile mlx...]"
	@$(MAKE) -C $ $(MLX_PATH)
	@echo "\033[32m[Compile So_long...]"
	@$(GCC) -o $(NAME) ${OBJ} $(FLAGS) $(LIB) $(MLX)
	@echo "\033[32m[JOB DONE ! YOU CAN RUN THE GAME :D]"

bonus: $(NAME_BONUS)
$(NAME_BONUS):${OBJ_BONUS}
	@echo "\033[32m[Compile Lib]"
	@$(MAKE) -C $ $(LIBFT_PATH)
	@echo "\033[32m[Compile mlx]"
	@$(MAKE) -C $ $(MLX_PATH)
	@echo "\033[32m[Compile So_long_bonus...]"
	@$(GCC) -o $(NAME_BONUS) ${OBJ_BONUS} $(FLAGS) $(LIB) $(MLX)
	@echo "\033[32m[JOB DONE ! YOU CAN RUN THE GAME :D]"

clean:
	@rm -rf $(OBJ)
	@rm -rf $(OBJ_BONUS)
	@echo "\033[32m[Clean-UP DONE]"
	
fclean: clean
	@$(MAKE) -C $ $(LIBFT_PATH) fclean
	@$(MAKE) -C $ $(MLX_PATH) clean
	@rm -rf $(NAME)
	@rm -rf $(NAME_BONUS)
	@echo "\033[32m[Clean-UP DONE]"

re: fclean all

0: all clean

