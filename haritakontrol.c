/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   haritakontrol.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygoksu <ygoksu@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 17:35:38 by ygoksu            #+#    #+#             */
/*   Updated: 2022/08/25 17:35:40 by ygoksu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_control(t_vars *ysf)
{
	int	i;
	int	j;

	i = 0;
	while (ysf->map[i])
	{
		j = 0;
		while (ysf->map[i][j])
		{
			if (ysf->map[i][j] == 'P')
			{
				ysf->harida->player_cnt++;
				ysf->chr->o_x = j;
				ysf->chr->o_y = i;
			}
			if (ysf->map[i][j] == 'C')
				ysf->harida->cat_cnt++;
				j++;
		}
		i++;
	}
	player_control2(ysf);
}

void	player_control2(t_vars *ysf)
{
	if (ysf->harida->player_cnt != 1)
	{
		ft_printf("Error\nOyuncu sayisi hatasi!");
		exit (0);
	}
	if (ysf->harida->cat_cnt < 1)
	{
		ft_printf("Error\nKedi sayisi hatasi!");
		exit (0);
	}
}

void	exit_control(t_vars *ysf)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	ysf->harida->exit_cnt = 0;
	while (ysf->map[i])
	{
		while (ysf->map[i][j])
		{
			if (ysf->map[i][j] == 'E')
				ysf->harida->exit_cnt++;
				j++;
		}
		i++;
		j = 0;
	}
	if (ysf->harida->exit_cnt < 1)
	{
		ft_printf("Error\nCikis sayisi hatasi!");
		exit (0);
	}
}

void	wall_control(t_vars *ysf)
{
	int	i;

	i = 0;
	while (i < ysf->w)
	{
		if (ysf->map[ysf->h - 1][i] != '1' ||
				ysf->map[0][i] != '1')
		{
			ft_printf("Error\nDuvar hatasi!");
			exit (0);
		}
		i++;
	}
		i = 0;
	while (i < ysf->h)
	{
		if (ysf->map[i][0] != '1' ||
				ysf->map[i][ysf->w - 1] != '1')
		{
			ft_printf("Error\nDuvar hatasi!");
			exit (0);
		}
	i++;
	}
}
