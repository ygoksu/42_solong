#include "so_long_bonus.h"

void    puts_enemy(t_vars   *ysf)
{
	static	int	fl = 0;//baska yerde tanimla
	if (ysf->map[ysf->chr->e_y][ysf->chr->e_x + 1] != '1' && fl == 0)
	{	
	mlx_put_image_to_window(ysf->mlx, ysf->win,
			ysf->enemy1, (ysf->chr->e_x + 1) * 64,ysf->chr->e_y * 64);
	ysf->chr->e_x++;
	if (ysf->map[ysf->chr->e_y][ysf->chr->e_x + 1] == '1')
		fl = 1;
	}
	else if (ysf->map[ysf->chr->e_y][ysf->chr->e_x - 1] != '1' && fl == 1)
	{
		mlx_put_image_to_window(ysf->mlx, ysf->win,
				ysf->enemy2, (ysf->chr->e_x - 1) * 64, ysf->chr->e_y * 64);
		ysf->chr->e_y--;
		if (ysf->map[ysf->chr->e_y][ysf->chr->e_x - 1] == '1')
			fl = 0;
	}
}

void    find_enemy(t_vars   *ysf)
{
	int	i;
	int	j;

	i = 0;
	while (ysf->map[i++][j])
	{
		while (ysf->map[i][j++])
		{
			if (ysf->map[i][j] == 'D')
			{
				ysf->harida->enemy_cnt++;
				ysf->chr->e_x = j;
				ysf->chr->e_y = i;
			}
				
		}
	}
	if (ysf->harida->enemy_cnt < 1)
	{
		ft_printf("Dusman sayisi hatasi!");
		exit (0);
	}
}

if (ysf->chr->o_x == ysf->chr->e_x && ysf->chr->o_y == ysf->chr->e_y)
	close_frame(ysf);
