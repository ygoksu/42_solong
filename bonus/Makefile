NAME		= libft.a
LIBFT		= ./ft_printf/
CC			= gcc
FLAGS		= ./*.c ./getnextline/get_next_line.c ./getnextline/get_next_line_utils.c ./libftprintf.a -framework OpenGL -framework AppKit -L ./minilibx -lmlx -Wall -Wextra -Werror
RM			= rm -f
AR			= ar rcs

SRC			= $(wildcard *.c)

all:		$(NAME) derle

$(NAME):	$(OBJ)
			make -C $(LIBFT)
			cp ft_printf/libftprintf.a .


derle:
			$(CC) $(FLAGS)
			mv ./a.out so_long_bonus

clean:
			rm -f ./libft.a
			make clean -C $(LIBFT)

fclean:		clean
	@$(RM) -f ./libftprintf.a
	@$(RM) -f $(LIBFT)/libftprintf.a
	@$(RM) -f so_long_bonus

re:			fclean all

.PHONY:		all clean fclean re derle