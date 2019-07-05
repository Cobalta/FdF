/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fdf.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: brey-gal <brey-gal@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/03 20:41:09 by brey-gal     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/03 20:41:09 by brey-gal    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdio.h>
int		deal_key(int key, t_win *win)
{
	if (key == 53)
	{
		win_del(win);
		exit(1);
	}
	return 0;
}

int		fdf(t_win *win, t_map *map)
{
	t_vec	*vec;

	win->x = 2560;
	win->y = 1315;
	win->mlx_ptr = mlx_init();
	win->win_ptr = mlx_new_window(win->mlx_ptr, win->x, win->y, "FdF");
	//mlx_expose_hook(win->win_ptr, render, win);
	vec = vec_new();
	map_to_struct(map, vec);

	vec_del(vec);

	render(win);
	mlx_key_hook(win->win_ptr, deal_key, win);
	mlx_loop(win->mlx_ptr);

	return (0);
}
