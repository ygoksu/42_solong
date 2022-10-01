/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   haritalar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygoksu <ygoksu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 17:35:12 by ygoksu            #+#    #+#             */
/*   Updated: 2022/09/01 16:24:02 by ygoksu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	puts_door(t_vars *ysf)
{
	int	i;
	int	j;

	i = 0;
	while (i < ysf->h)
	{
		j = 0;
		while (j < ysf->w)
		{
			if (ysf->map[ysf->chr->o_y][ysf->chr->o_x] == 'E'
			&& ysf->harida->cat_cnt == 0)
			{
				close_frame(ysf);
				exit(0);
			}
			if (ysf->map[i][j] == 'E' && ysf->harida->cat_cnt != 0)
				mlx_put_image_to_window(ysf->mlx, ysf->win,
					ysf->end_closed, j * 64, i * 64);
			else if (ysf->map[i][j] == 'E' && ysf->harida->cat_cnt == 0)
				mlx_put_image_to_window(ysf->mlx, ysf->win,
					ysf->end_open, j * 64, i * 64);
					j++;
		}
		i++;
	}
}

void	dosya_oku(t_vars *ysf, char *path)
{
	int	fd;
	int	i;
	int	j;
	int	flag;

	flag = 0;
	j = 0;
	i = 0;
	fd = open(path, O_RDONLY);
	while (1)
	{
		ysf->map[i] = get_next_line(fd);
		if (flag == 0)
		{
			flag = 1;
			j = ft_strlen(ysf->map[0]) - 1;
		}
		if (!ysf->map[i])
			break ;
		i++;
	}
	ysf->w = j;
	ysf->h = i;
	close(fd);
}

void	filename_control(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 1)
	{
		ft_printf("Error\nDosya ismini yanlis girdiniz!");
		close(fd);
		exit(1);
	}
	close(fd);
}

int	close_frame(t_vars *ysf)
{
	int		i;
	t_vars	*finisher;

	finisher = ysf;
	i = 0;
	mlx_destroy_image(finisher->mlx, finisher->chr->chrs);
	mlx_destroy_image(finisher->mlx, finisher->walle);
	mlx_destroy_image(finisher->mlx, finisher->backg);
	mlx_destroy_image(finisher->mlx, finisher->catimg1);
	mlx_destroy_image(finisher->mlx, finisher->catimg2);
	mlx_destroy_image(finisher->mlx, finisher->end_closed);
	mlx_destroy_image(finisher->mlx, finisher->end_open);
	mlx_destroy_image(finisher->mlx, finisher->enemy1);
	mlx_destroy_image(finisher->mlx, finisher->enemy2);
	mlx_destroy_window(finisher->mlx, finisher->win);
	free(finisher->chr);
	free(finisher->harida);
	while (i <= finisher->h)
		free(finisher->map[i++]);
	free(finisher);
	exit(0);
	return (0);
}
