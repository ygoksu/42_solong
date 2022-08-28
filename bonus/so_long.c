/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygoksu <ygoksu@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 15:59:43 by ygoksu            #+#    #+#             */
/*   Updated: 2022/08/25 16:20:44 by ygoksu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long_bonus.h"

int	loop(t_vars *ysf)
{
	int	m;

	m = 0;
	while (m < 50000000)
		m++;
	puts_backgwall(ysf);
	puts_cat(ysf);
	puts_door(ysf);
	puts_character(ysf);
	puts_enemy(ysf);
	puts_string(ysf);
	mlx_hook(ysf->win, 17, 0, close_frame, ysf);
	return (0);
}

void	open_window(t_vars	*ysf, char	*path)
{
	dosya_oku(ysf, path);
	ysf->x = ysf->w;
	ysf->y = ysf->h;
	ysf->harida->player_cnt = 0;
	ysf->harida->cat_cnt = 0;
	ysf->harida->enemy_cnt = 0;
	player_control(ysf);
	exit_control(ysf);
	wall_control(ysf);
	find_enemy(ysf);
	ysf->mlx = mlx_init();
	ysf->win = mlx_new_window(ysf->mlx, ysf->w * 64, ysf->h * 64, "Game");
	get_img(ysf);
	get_img2(ysf);
	mlx_hook(ysf->win, 2, 1, &keygen1, ysf);
	mlx_loop_hook(ysf->mlx, &loop, ysf);
	mlx_loop(ysf->mlx);
}

int	main(int argc, char *argv[])
{
	t_vars	*ysf;

	if (argc == 2)
	{
		ysf = malloc(sizeof(t_vars));
		ysf->chr = malloc(sizeof(t_char));
		ysf->map = (char **)malloc(sizeof(char *) * 100);
		ysf->harida = malloc(sizeof(t_map));
		ysf->chr->puan = 1;
		xpm_control1();
		xpm_control2();
		xpm_control3();
		path_checker(argv[1]);
		filename_control(argv[1]);
		open_window(ysf, argv[1]);
	}
	else
		ft_printf("Eksik/Fazla arguman");
	return (0);
}