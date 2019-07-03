/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_fdf.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: brey-gal <brey-gal@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/03 20:41:09 by brey-gal     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/03 20:41:09 by brey-gal    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		deal_key(int key, t_win *win)
{
	if (key == 53)
	{
		ft_win_del(win);
		exit(1);
	}
	return 0;
}

int		ft_fdf(t_win *win)
{
	t_coor coor;

	win->x = 2560;
	win->y = 1315;
	win->mlx_ptr = mlx_init();
	win->win_ptr = mlx_new_window(win->mlx_ptr, win->x, win->y, "FdF");
	mlx_key_hook(win->win_ptr, deal_key, win);
	mlx_loop(win->mlx_ptr);
	return (0);
}
