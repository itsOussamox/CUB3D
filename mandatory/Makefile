# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aabdou <aabdou@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/08 20:35:45 by obouadel          #+#    #+#              #
#    Updated: 2022/08/22 14:02:34 by aabdou           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CC = cc

FLAGS = -Wall -Wextra -Werror #-g -fsanitize=address

RM = rm -f


SRCS =	main.c\
		./src/parsing/arg_parsing.c\
		./utils/GetNextLine/get_next_line_utils.c\
		./utils/GetNextLine/get_next_line.c\
		./src/parsing/map_parsing.c\
		./src/parsing/free.c\
		./src/parsing/utils.c\
		./src/parsing/new_split.c\
		./src/parsing/check_map.c\
		./src/parsing/check_color.c\
		./src/rendering/cubed.c\
		./src/rendering/draws.c\
		./src/rendering/draws2.c\
		./src/rendering/player_data.c\
		./src/rendering/player_movements.c\
		./src/rendering/player_movmentes2.c\
		./src/rendering/ray_cast.c\
		./src/rendering/ray_utils.c\
		./src/rendering/ray_utils2.c\
		./src/rendering/render_utils.c\
		./src/rendering/render_utils2.c\
		./src/rendering/colors.c\
		./src/rendering/utils.c\
		./src/rendering/utils2.c\
		./src/parsing/utils2.c

LIB =	./includes/parsing.h\
		./includes/cubed.h\
		./mlx/mlx.h

MLX_LIB = ./mlx

MLX_FLAG = -L./mlx -lmlx -framework openGL -framework AppKit

OBJT = $(SRCS:.c=.o)

all : $(NAME)

$(NAME): $(OBJT) LIBFT
	@make -C $(MLX_LIB)
	$(CC) $(FLAGS) $(MLX_FLAG) $(OBJT)  ./utils/libft/libft.a -o $(NAME)

%.o : %.c $(LIB)
	$(CC) $(FLAGS) -o $@ -c $<


LIBFT :
	@make -C ./utils/libft


clean:
	$(RM) $(OBJT)
	@make -C ./utils/libft clean
	@make -C ./mlx clean

fclean:
	$(RM) $(OBJT) $(NAME)
	@make -C ./utils/libft fclean
	@make -C ./mlx clean

re:	fclean all

.PHONY: all fclean clean re
