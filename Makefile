NAME		= so_long
BNAME		= so_long_bonus
LIBFT		= ft_printf/libft
CC			= gcc
FLAGS		= -framework OpenGL -framework AppKit -L ./minilibx -lmlx -Wall -Wextra -Werror
RM			= rm -f
PRINTF		= ft_printf/libftprintf.a
GNL			= getnextline/get_next_line.c getnextline/get_next_line_utils.c
MLX			= libmlx.a
B_SRC		= bonus/*.c
SRC			= $(wildcard Main/*.c)

all:		$(NAME)
			@echo DONE

$(NAME):	$(SRC) $(PRINTF) $(MLX)
	gcc $(SRC) $(PRINTF) $(GNL) $(FLAGS) $(MLX) -o so_long
	@echo "ACCOMPLİSHED"

$(PRINTF) :
	make -C ft_printf

$(MLX) :
	make -C minilibx
	cp minilibx/libmlx.a .

bonus:	$(BNAME)
	@echo "ACCOMPLİSHED BONUS"

$(BNAME):	$(B_SRC) $(PRINTF) $(MLX)
	gcc $(B_SRC) $(PRINTF) $(GNL) $(FLAGS) $(MLX) -o so_long_bonus

clean:
			make clean -C ft_printf
			make clean -C minilibx
			rm -rf libmlx.a

fclean:		clean
	@$(RM) -f ft_printf/libftprintf.a
	@$(RM) -f so_long so_long_bonus

re:			fclean all

.PHONY:		all clean fclean re