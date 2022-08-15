#ifndef SO_LONG_H
# define SO_LONG_H

# include "./ft_printf/ft_printf.h"
# include "./minilibx/mlx.h"
# include "./getnextline/get_next_line.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2

typedef struct s_char
{
    char    *chr_left;
    char    *chr_right;
    char    *chr_front;
    char    *chr_back;
    char    *chr_curr;

    int     l_x;
    int     l_y;

}t_char;

typedef struct s_map
{
    
}t_map;

typedef struct s_vars
{
    void    *mlx;
    void    *win;

    
}t_vars;

typedef struct mystructs
{
    
}mystruct;




#endif