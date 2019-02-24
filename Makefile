NAME = fillit
SRCS = 	main.c\
				check_file.c\
				add_tetrimino.c\
				check_for_tetriminos.c\
				create_map.c\
				algorithm.c\
				list_size.c\
				display_solution.c\
				cleaning_dots.c\
				cleaning_columns.c\

INCLUDES = -I fillit.h
LIBFT = libft/libft.a
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	make -C libft
	gcc $(FLAGS) $(INCLUDES) $(SRCS) $(LIBFT) -o $(NAME)

clean:
	make -C libft clean

fclean: clean
	/bin/rm -f $(NAME)
	make -C libft fclean

re: fclean all
