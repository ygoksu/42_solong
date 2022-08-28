/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keygen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygoksu <ygoksu@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 17:35:54 by ygoksu            #+#    #+#             */
/*   Updated: 2022/08/25 17:35:56 by ygoksu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	keygen1(int keycode, t_vars *ysf)
{
	if (keycode == W)
	{
		if (ysf->map[ysf->chr->o_y - 1][ysf->chr->o_x] == '1')
			return (0);
		if (ysf->map[ysf->chr->o_y - 1][ysf->chr->o_x] == 'E'
		&& ysf->harida->cat_cnt != 0)
			return (0);
		ysf->chr->o_y -= 1;
	}
	if (keycode == A)
	{
		if (ysf->map[ysf->chr->o_y][ysf->chr->o_x - 1] == '1')
			return (0);
		if (ysf->map[ysf->chr->o_y][ysf->chr->o_x - 1] == 'E'
		&& ysf->harida->cat_cnt != 0)
			return (0);
	ysf->chr->o_x -= 1;
	}
	ft_printf("%d\n", ysf->chr->puan);
	ysf->chr->puan++;
	keygen2(keycode, ysf);
	return (0);
}

int	keygen2(int keycode, t_vars *ysf)
{
	if (keycode == S)
	{
		if (ysf->map[ysf->chr->o_y + 1][ysf->chr->o_x] == '1')
			return (0);
		if (ysf->map[ysf->chr->o_y + 1][ysf->chr->o_x] == 'E'
		&& ysf->harida->cat_cnt != 0)
			return (0);
	ysf->chr->o_y += 1;
	}
	if (keycode == D)
	{
		if (ysf->map[ysf->chr->o_y][ysf->chr->o_x + 1] == '1')
			return (0);
		if (ysf->map[ysf->chr->o_y][ysf->chr->o_x + 1] == 'E'
		&& ysf->harida->cat_cnt != 0)
			return (0);
	ysf->chr->o_x += 1;
	}
	if (keycode == ESC)
		exit(0);
	return (0);
}

void	puts_string(t_vars *ysf)
{	
	int		i;
	int		j;
	char	*str;
	char	*adder;

	i = 0;
	while (i < 20)
	{
		j = 0;
		while (j < 63)
		{
			mlx_pixel_put(ysf->mlx, ysf->win, j, i, 0x660099);
			j++;
		}
		i++;
	}
	str = malloc(sizeof(char *) * 20);
	ft_strlcat(str, "Move:", 7);
	adder = ft_itoa(ysf->chr->puan);
	ft_strlcat(str, adder, 10);
	mlx_string_put(ysf->mlx, ysf->win, 5, 15, 0xFFFFFF, str);
	free(str);
	free(adder);
}
