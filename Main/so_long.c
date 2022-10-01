/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygoksu <ygoksu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 15:59:43 by ygoksu            #+#    #+#             */
/*   Updated: 2022/10/01 11:21:22 by ygoksu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	loop(t_vars *ysf)
{
	puts_backgwall(ysf);
	puts_cat(ysf);
	puts_door(ysf);
	puts_character(ysf);
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
	rectangular_check(ysf);
	player_control(ysf);
	exit_control(ysf);
	wall_control(ysf);
	unknown_control(ysf);
	ysf->mlx = mlx_init();
	ysf->win = mlx_new_window(ysf->mlx, ysf->w * 64, ysf->h * 64, "Game");
	get_img(ysf);
	mlx_hook(ysf->win, 2, 1, &keygen1, ysf);
	mlx_loop_hook(ysf->mlx, &loop, ysf);
	mlx_loop(ysf->mlx);
}

void	rectangular_check(t_vars	*ysf)
{
	int	i;
	int	j;

	i = 0;
	while (i < ysf->h)
	{
		j = 0;
		while (ysf->map[i][j] != '\n' && ysf->map[i][j] != '\0')
			j++;
		if (ysf->w != j)
		{
			ft_printf("Haritaniz dikdortgen degil!");
			exit(0);
		}
		i++;
	}
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
		ysf->chr->puan = 0;
		xpm_control1();
		xpm_control2();
		path_checker(argv[1]);
		filename_control(argv[1]);
		open_window(ysf, argv[1]);
	}
	else
		ft_printf("Eksik/Fazla arguman");
	return (0);
}
