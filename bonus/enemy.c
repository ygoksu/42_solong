/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygoksu <ygoksu@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 17:00:04 by ygoksu            #+#    #+#             */
/*   Updated: 2022/08/28 17:00:06 by ygoksu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	puts_enemy(t_vars *ysf)
{
	static int	fl;

	if (ysf->map[ysf->chr->e_y][ysf->chr->e_x + 1] != '1' && fl == 0)
	{
		mlx_put_image_to_window(ysf->mlx, ysf->win,
			ysf->enemy2, (ysf->chr->e_x + 1) * 64, ysf->chr->e_y * 64);
	ysf->chr->e_x++;
		if (ysf->map[ysf->chr->e_y][ysf->chr->e_x + 1] == '1')
			fl = 1;
	}
	else if (ysf->map[ysf->chr->e_y][ysf->chr->e_x - 1] != '1' && fl == 1)
	{
		mlx_put_image_to_window(ysf->mlx, ysf->win,
			ysf->enemy1, (ysf->chr->e_x - 1) * 64, ysf->chr->e_y * 64);
		ysf->chr->e_x--;
		if (ysf->map[ysf->chr->e_y][ysf->chr->e_x - 1] == '1')
			fl = 0;
	}
	alive(ysf);
}

void	find_enemy(t_vars *ysf)
{
	int	i;
	int	j;

	i = 0;
	while (ysf->map[i])
	{
		while (ysf->map[i][j])
		{
			if (ysf->map[i][j] == 'D')
			{
				ysf->harida->enemy_cnt++;
				ysf->chr->e_x = j;
				ysf->chr->e_y = i;
			}
				j++;
		}
		i++;
	j = 0;
	}
	if (ysf->harida->enemy_cnt < 1)
	{
		ft_printf("Error\nDusman sayisi hatasi!");
		exit (0);
	}
}

void	alive(t_vars *ysf)
{
	if (ysf->chr->o_x == ysf->chr->e_x && ysf->chr->o_y == ysf->chr->e_y)
		close_frame(ysf);
}

void	get_img2(t_vars *ysf)
{
	ysf->chr->chrss = mlx_xpm_file_to_image(ysf->mlx,
			"./img/characters.xpm", &(ysf->x), &(ysf->y));
	ysf->chr->chrsl = mlx_xpm_file_to_image(ysf->mlx,
			"./img/characterl.xpm", &(ysf->x), &(ysf->y));
}
void	delete_cat(t_vars *ysf)
{
	int	i;
	int	j;

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
