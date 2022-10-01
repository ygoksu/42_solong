/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygoksu <ygoksu@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 16:26:46 by ygoksu            #+#    #+#             */
/*   Updated: 2022/08/25 17:31:12 by ygoksu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	int	i;
	int	j;

	mlx_put_image_to_window(ysf->mlx, ysf->win,
		ysf->chr->chrs, (ysf->chr->o_x) * 64, (ysf->chr->o_y) * 64);
	i = 0;
	while (i < ysf->h)
	{
		j = 0;
		while (j < ysf->w)
		{
			if (ysf->map[ysf->chr->o_y][ysf->chr->o_x] == 'C')
			{
				ysf->map[ysf->chr->o_y][ysf->chr->o_x] = '0';
				ysf->harida->cat_cnt--;
			}
			j++;
		}
		i++;
	}
}

void	puts_cat(t_vars *ysf)
{
	int			i;
	int			j;

	i = 0;
	while (i < ysf->h)
	{
		j = 0;
		while (j < ysf->w)
		{
			if (ysf->map[i][j] == 'C')
				mlx_put_image_to_window(ysf->mlx, ysf->win,
					ysf->catimg, j * 64, i * 64 + 5);
			j++;
		}
		i++;
	}
}

void	get_img(t_vars *ysf)
{
	ysf->chr->chrs = mlx_xpm_file_to_image(ysf->mlx,
			"./img/character2.xpm", &(ysf->x), &(ysf->y));
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
}
