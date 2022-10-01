/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygoksu <ygoksu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 12:34:17 by ygoksu            #+#    #+#             */
/*   Updated: 2022/10/01 12:02:56 by ygoksu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../ft_printf/ft_printf.h"
# include "../minilibx/mlx.h"
# include "../getnextline/get_next_line.h"
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
	void	*chrs;
	void	*chrss;
	void	*chrsl;
	int		puan;
	int		o_x;
	int		o_y;
	int		e_x;
	int		e_y;

}t_char;

typedef struct s_map
{
	int	enemy_cnt;
	int	cat_cnt;
	int	exit_cnt;
	int	player_cnt;
}t_map;

typedef struct s_vars
{
	void	*mlx;
	void	*win;

	t_char	*chr;
	t_map	*harida;

	void	*backg;
	void	*walle;
	void	*end_open;
	void	*end_closed;
	void	*catimg;
	void	*catimg1;
	void	*catimg2;
	void	*enemy1;
	void	*enemy2;

	int		h;
	int		w;
	int		x;
	int		y;
	char	**map;
}t_vars;

void	dosya_oku(t_vars *ysf, char *path);
void	filename_control(char *path);
void	xpm_control1(void);
void	xpm_control2(void);
void	xpm_control3(void);
void	path_checker(char *path);
void	puts_img(t_vars *ysf);
void	get_img(t_vars *ysf);
void	get_img2(t_vars *ysf);
void	player_control(t_vars *ysf);
void	exit_control(t_vars *ysf);
void	puts_character(t_vars *ysf);
void	puts_cat(t_vars *ysf);
void	puts_door(t_vars *ysf);
void	puts_backgwall(t_vars *ysf);
void	puts_enemy(t_vars *ysf);
void	alive(t_vars *ysf);
void	find_enemy(t_vars *ysf);
int		keygen2(int keycode, t_vars *ysf);
void	wall_control(t_vars *ysf);
void	player_control2(t_vars *ysf);
int		keygen1(int keycode, t_vars *ysf);
int		close_frame(t_vars *ysf);
void	puts_string(t_vars *ysf);
void	delete_cat(t_vars *ysf);
void	unknown_control(t_vars *ysf);
void	rectangular_check(t_vars *ysf);
#endif