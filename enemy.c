#include "so_long_bonus.h"

void    puts_enemy(t_vars   *ysf)
{

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
				ysf->chr->e_x = j;
				
			}
				
		}
	}
}
