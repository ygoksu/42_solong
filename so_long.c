/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygoksu <ygoksu@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 15:46:09 by ygoksu            #+#    #+#             */
/*   Updated: 2022/08/09 15:51:13 by ygoksu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

1 int closes(int keycode, t_vars *vars)
{
    keycode = 0;
    mlx_destroy_window(vars->mlx, vars->win);
    return (0);
}
// int key_hook(t_vars *vars)
// {
//     vars = NULL;
//     ft_printf("Hello from keyhoook!\n");
//     return (0);
// // }
// int mouse_hook(int keycode, t_vars *vars)
// {
//     vars = NULL;
//     if(keycode == 1)
//     ft_printf("safasf");
//     if(keycode == 2)
//     ft_printf("right");
//     return (0);
// }

int render_next_frame(t_char    *my);
{
    
}


int main(void)
{
    t_vars vars;
    void *mlx;
    t_char my;
    mlx = mlx_init();
    mlx_loop_hook(mlx, render_next_frame, &my);
    mlx_loop(mlx);
     vars.mlx = mlx_init();
     vars.win = mlx_new_window(vars.mlx, 1024, 768, "Yusuf Goksu");
   // mlx_key_hook(vars.win, key_hook, &vars);
    mlx_hook(vars.win, 2, 1L<<0, closes, &vars);
   //mlx_mouse_hook(vars.win, mouse_hook, &vars);
    mlx_loop(vars.mlx);
}