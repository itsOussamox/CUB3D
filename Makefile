NAME = cub3D

CC = cc

FLAGS = -g -Wall -Wextra -Werror #-fsanitize=address

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
		./src/parsing/check_color.c

LIB =	./includes/parsing.h


OBJT = $(SRCS:.c=.o)


$(NAME): $(OBJT) LIBFT
	$(CC) $(FLAGS) $(OBJT)  ./utils/libft/libft.a -o $(NAME)

%.o : %.c $(LIB)
	$(CC) $(FLAGS) -o $@ -c $<

all : $(NAME)

LIBFT :
	@make -C ./utils/libft

clean:
	$(RM) $(OBJT)
	@make -C ./utils/libft clean

fclean:
	$(RM) $(OBJT) $(NAME)
	@make -C ./utils/libft fclean

re:	fclean all

.PHONY: all fclean clean re
