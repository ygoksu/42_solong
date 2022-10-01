/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygoksu <ygoksu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 16:26:46 by ygoksu            #+#    #+#             */
/*   Updated: 2022/10/01 12:10:31 by ygoksu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	puts_backgwall(t_vars *ysf)
{
	int	i;
	int	j;

	i = 0;
	while (i < ysf->h)
	{
		j = 0;
		while (j < ysf->w)
		{
			mlx_put_image_to_window(ysf->mlx, ysf->win,
				ysf->backg, j * 64, i * 64);
			if (ysf->map[i][j] == '1')
				mlx_put_image_to_window(ysf->mlx, ysf->win,
					ysf->walle, j * 64, i * 64);
			j++;
		}
		i++;
	}
}

void	puts_wall(t_vars *ysf)
{
	int	i;
	int	j;

	i = 0;
	while (i < ysf->h)
	{
		j = 0;
		while (j < ysf->w)
		{
			if (ysf->map[i][j] == '1')
				mlx_put_image_to_window(ysf->mlx, ysf->win,
					ysf->walle, j * 64, i * 64);
			j++;
		}
		i++;
	}
}

void	puts_character(t_vars *ysf)
{
	static int	k;

	k++;
	if (k % 3 == 0)
		mlx_put_image_to_window(ysf->mlx, ysf->win,
			ysf->chr->chrs, (ysf->chr->o_x) * 64, (ysf->chr->o_y) * 64);
	else if (k % 3 == 1)
		mlx_put_image_to_window(ysf->mlx, ysf->win,
			ysf->chr->chrss, (ysf->chr->o_x) * 64, (ysf->chr->o_y) * 64);
	else
		mlx_put_image_to_window(ysf->mlx, ysf->win,
			ysf->chr->chrsl, (ysf->chr->o_x) * 64, (ysf->chr->o_y) * 64);
	delete_cat(ysf);
}

void	puts_cat(t_vars *ysf)
{
	int			i;
	int			j;
	static int	k;

	i = 0;
	k++;
	while (i < ysf->h)
	{
		j = 0;
		while (j < ysf->w)
		{
			if (ysf->map[i][j] == 'C' && k % 3 == 0)
				mlx_put_image_to_window(ysf->mlx, ysf->win,
					ysf->catimg, j * 64, i * 64 + 5);
			if (ysf->map[i][j] == 'C' && k % 3 == 2)
				mlx_put_image_to_window(ysf->mlx, ysf->win,
					ysf->catimg1, j * 64, i * 64 + 5);
			if (ysf->map[i][j] == 'C' && k % 3 == 1)
				mlx_put_image_to_window(ysf->mlx, ysf->win,
					ysf->catimg2, j * 64, i * 64 + 5);
			j++;
		}
		i++;
	}
}

void	get_img(t_vars *ysf)
{
	ysf->chr->chrs = mlx_xpm_file_to_image(ysf->mlx,
			"./img/character.xpm", &(ysf->x), &(ysf->y));
	ysf->walle = mlx_xpm_file_to_image(ysf->mlx,
			"./img/wall.xpm", &(ysf->x), &(ysf->y));
	ysf->backg = mlx_xpm_file_to_image(ysf->mlx,
			"./img/background1.xpm", &(ysf->x), &(ysf->y));
	ysf->catimg = mlx_xpm_file_to_image(ysf->mlx,
			"./img/cat.xpm", &(ysf->x), &(ysf->y));
	ysf->catimg1 = mlx_xpm_file_to_image(ysf->mlx,
			"./img/cat1.xpm", &(ysf->x), &(ysf->y));
	ysf->catimg2 = mlx_xpm_file_to_image(ysf->mlx,
			"./img/cat2.xpm", &(ysf->x), &(ysf->y));
	ysf->end_closed = mlx_xpm_file_to_image(ysf->mlx,
			"./img/door.xpm", &(ysf->x), &(ysf->y));
	ysf->end_open = mlx_xpm_file_to_image(ysf->mlx,
			"./img/doormeftuh.xpm", &(ysf->x), &(ysf->y));
	ysf->enemy1 = mlx_xpm_file_to_image(ysf->mlx,
			"./img/enemyleft.xpm", &(ysf->x), &(ysf->y));
	ysf->enemy2 = mlx_xpm_file_to_image(ysf->mlx,
			"./img/enemyright.xpm", &(ysf->x), &(ysf->y));
}
