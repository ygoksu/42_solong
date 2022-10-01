/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keygen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygoksu <ygoksu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 17:35:54 by ygoksu            #+#    #+#             */
/*   Updated: 2022/10/01 12:26:21 by ygoksu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	keygen1(int keycode, t_vars *ysf)
{
	if (keycode == W)
	{
		if (ysf->map[ysf->chr->o_y - 1][ysf->chr->o_x] == '1')
			return (0);
		if (ysf->map[ysf->chr->o_y - 1][ysf->chr->o_x] == 'E'
		&& ysf->harida->cat_cnt != 0)
			return (0);
			ysf->chr->puan++;
		ft_printf("%d\n", ysf->chr->puan);
		ysf->chr->o_y -= 1;
	}
	if (keycode == A)
	{
		if (ysf->map[ysf->chr->o_y][ysf->chr->o_x - 1] == '1')
			return (0);
		if (ysf->map[ysf->chr->o_y][ysf->chr->o_x - 1] == 'E'
		&& ysf->harida->cat_cnt != 0)
			return (0);
			ysf->chr->puan++;
		ft_printf("%d\n", ysf->chr->puan);
	ysf->chr->o_x -= 1;
	}
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
			ysf->chr->puan++;
		ft_printf("%d\n", ysf->chr->puan);
	ysf->chr->o_y += 1;
	}
	if (keycode == D)
	{
		if (ysf->map[ysf->chr->o_y][ysf->chr->o_x + 1] == '1')
			return (0);
		if (ysf->map[ysf->chr->o_y][ysf->chr->o_x + 1] == 'E'
		&& ysf->harida->cat_cnt != 0)
			return (0);
			ysf->chr->puan++;
		ft_printf("%d\n", ysf->chr->puan);
	ysf->chr->o_x += 1;
	}
	if (keycode == ESC)
		exit(0);
	return (0);
}
