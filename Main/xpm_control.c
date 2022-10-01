/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygoksu <ygoksu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 17:36:05 by ygoksu            #+#    #+#             */
/*   Updated: 2022/09/02 17:34:21 by ygoksu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	xpm_control1(void)
{
	int	fd_character;
	int	fd_background;
	int	fd_wall;

	fd_character = open("./img/character.xpm", O_RDWR);
	fd_wall = open("./img/wall.xpm", O_RDWR);
	fd_background = open("./img/background.xpm", O_RDWR);
	if (fd_character <= 0 || fd_wall <= 0 || fd_background <= 0)
	{
		ft_printf("Error\nXpm dosyasi yok.");
		close(fd_character);
		close(fd_wall);
		close(fd_background);
		exit(1);
	}
}

void	xpm_control2(void)
{
	int	fd_cat;
	int	fd_door;
	int	fd_door2;

	fd_cat = open("./img/cat.xpm", O_RDWR);
	fd_door = open("./img/door.xpm", O_RDWR);
	fd_door2 = open("./img/doormeftuh.xpm", O_RDWR);
	if (fd_cat <= 0 || fd_door <= 0 || fd_door2 <= 0)
	{
		ft_printf("Error\nXpm dosyasi yok.");
		close(fd_cat);
		close(fd_door);
		close(fd_door2);
		exit(1);
	}
}

void	unknown_control(t_vars *ysf)
{
	int	i;
	int	j;

	i = 0;
	while (ysf->map[i])
	{
		j = 0;
		while (ysf->map[i][j] != '\n' && ysf->map[i][j] != '\0')
		{
			if (ysf->map[i][j] != '0'
				&& ysf->map[i][j] != '1'
				&& ysf->map[i][j] != 'P'
				&& ysf->map[i][j] != 'C'
				&& ysf->map[i][j] != 'E')
			{
				ft_printf("Error\nBilinmeyen karakter");
				exit (0);
			}
			j++;
		}
	i++;
	}
}

void	path_checker(char *path)
{
	int	len;

	len = ft_strlen(path);
	if (ft_strncmp(&path[len - 4], ".ber", 4))
	{
		ft_printf("Error\nYol yok veya yol ismi yanlış.");
		exit(1);
	}
}
