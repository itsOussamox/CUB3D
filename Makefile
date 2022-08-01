NAME = cub3D

CC = cc

FLAGS = -g -Wall -Wextra -Werror -fsanitize=address

RM = rm -f

SRCS =	main.c\

LIB =	./includes/parsing.h


OBJT = $(SRCS:.c=.o)


$(NAME): $(OBJT) LIBFT
	$(CC) $(OBJT) $(FLAGS) ./utils/libft/libft.a -o $(NAME)

%.o : %.cpp $(LIB)
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
