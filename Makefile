NAME = so_long
CFLAGS =  -Wall -Wextra -Werror
LFLAGS = -framework Appkit -framework OpenGL -L./minilibx -lmlx
MLX = minilibx/libmlx.a
SRCS = so_long.c
PRINTF = ft_printf/libftprintf.a
GNL = getnextline/get_next_line.c getnextline/get_next_line_utils.c

OBJS = $(SRCS:.c=.o)

all: $(NAME) $(MLX) 

$(NAME) : $(OBJS) $(PRINTF)
	gcc $(OBJS) $(CFLAGS) $(PRINTF) $(GNL) $(LFLAGS)  $(MLX) -o $(NAME)
	@echo "ACCOMPLİSHED"
$(PRINTF) : 
	make -C ft_printf

$(MLX) :
	make -C minilibx

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS) $(NAME)