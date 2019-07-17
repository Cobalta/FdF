/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   displaymenu.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ebourgeo <ebourgeo@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/17 04:52:34 by ebourgeo     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/17 04:52:34 by ebourgeo    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	displaytext4(t_env *env)
{
	mlx_string_put(env->mlx_ptr, env->win_ptr,
			env->width - 500, 1000, 0xFF9900, "Orange");
	mlx_string_put(env->mlx_ptr, env->win_ptr,
			env->width - 500, 1050, 0x9900FF, "Purple");
	mlx_string_put(env->mlx_ptr, env->win_ptr,
			env->width - 500, 1100, 0xFFFF00, "Yellow");
	mlx_string_put(env->mlx_ptr, env->win_ptr,
			env->width - 500, 1150, 0xFD0EE1, "Pink");
	mlx_string_put(env->mlx_ptr, env->win_ptr,
				   100, 550, 0xa020f0, "4/6            | Horizontal Pan");
	mlx_string_put(env->mlx_ptr, env->win_ptr,
				   100, 600, 0xa020f0, "2/8            | Vertical Pan");
}

void	displaytext3(t_env *env)
{
	mlx_string_put(env->mlx_ptr, env->win_ptr,
			(env->width / 2) - 100, 850, 0x0000ff, "Blue");
	mlx_string_put(env->mlx_ptr, env->win_ptr,
			(env->width / 2) - 100, 900, 0x5C5C5C, "Black");
	mlx_string_put(env->mlx_ptr, env->win_ptr,
			(env->width / 2) - 100, 950, 0xffffff, "White");
	mlx_string_put(env->mlx_ptr, env->win_ptr,
			(env->width / 2) - 100, 1000, 0xFF9900, "Orange");
	mlx_string_put(env->mlx_ptr, env->win_ptr,
			(env->width / 2) - 100, 1050, 0x9900FF, "Purple");
	mlx_string_put(env->mlx_ptr, env->win_ptr,
			(env->width / 2) - 100, 1100, 0xFFFF00, "Yellow");
	mlx_string_put(env->mlx_ptr, env->win_ptr,
			(env->width / 2) - 100, 1150, 0xFD0EE1, "Pink");
	mlx_string_put(env->mlx_ptr, env->win_ptr,
			env->width - 500, 750, 0xff0000, "Red");
	mlx_string_put(env->mlx_ptr, env->win_ptr,
			env->width - 500, 800, 0x00ff00, "Green");
	mlx_string_put(env->mlx_ptr, env->win_ptr,
			env->width - 500, 850, 0x0000ff, "Blue");
	mlx_string_put(env->mlx_ptr, env->win_ptr,
			env->width - 500, 900, 0x5C5C5C, "Black");
	mlx_string_put(env->mlx_ptr, env->win_ptr,
			env->width - 500, 950, 0xffffff, "White");
}

void	displaytext2(t_env *env)
{
	mlx_string_put(env->mlx_ptr, env->win_ptr,
			env->width - 500, 700, 0xD8A4F9, "Change Top Color");
	mlx_string_put(env->mlx_ptr, env->win_ptr,
			100, 750, 0xff0000, "Red");
	mlx_string_put(env->mlx_ptr, env->win_ptr,
			100, 800, 0x00ff00, "Green");
	mlx_string_put(env->mlx_ptr, env->win_ptr,
			100, 850, 0x0000ff, "Blue");
	mlx_string_put(env->mlx_ptr, env->win_ptr,
			100, 900, 0x5C5C5C, "Black");
	mlx_string_put(env->mlx_ptr, env->win_ptr,
			100, 950, 0xffffff, "White");
	mlx_string_put(env->mlx_ptr, env->win_ptr,
			100, 1000, 0xFF9900, "Orange");
	mlx_string_put(env->mlx_ptr, env->win_ptr,
			100, 1050, 0x9900FF, "Purple");
	mlx_string_put(env->mlx_ptr, env->win_ptr,
			100, 1100, 0xFFFF00, "Yellow");
	mlx_string_put(env->mlx_ptr, env->win_ptr,
			100, 1150, 0xFD0EE1, "Pink");
	mlx_string_put(env->mlx_ptr, env->win_ptr,
			(env->width / 2) - 100, 750, 0xff0000, "Red");
	mlx_string_put(env->mlx_ptr, env->win_ptr,
			(env->width / 2) - 100, 800, 0x00ff00, "Green");
}

void	displaytext(t_env *env)
{
	mlx_string_put(env->mlx_ptr, env->win_ptr,
			(env->width / 2) - 22, 50, 0xD8A4F9, "MENU");
	mlx_string_put(env->mlx_ptr, env->win_ptr,
			100, 100, 0xD8A4F9, "Controls :");
	mlx_string_put(env->mlx_ptr, env->win_ptr,
			100, 150, 0xa020f0, "Up/Down        | Rotation X +/-");
	mlx_string_put(env->mlx_ptr, env->win_ptr,
			100, 200, 0xa020f0, "Left/Right     | Rotation Y +/-");
	mlx_string_put(env->mlx_ptr, env->win_ptr,
			100, 250, 0xa020f0, "Page Up/Down   | Rotation Z +/-");
	mlx_string_put(env->mlx_ptr, env->win_ptr,
			100, 300, 0xa020f0, "Scroll Up/Down | Zoom +/-");
	mlx_string_put(env->mlx_ptr, env->win_ptr,
			100, 350, 0xa020f0, "O/P            | Altitude +/-");
	mlx_string_put(env->mlx_ptr, env->win_ptr,
			100, 400, 0xa020f0, "D              | Reset View");
	mlx_string_put(env->mlx_ptr, env->win_ptr,
			100, 450, 0xa020f0, "F              | Isometric View");
	mlx_string_put(env->mlx_ptr, env->win_ptr,
			100, 500, 0xa020f0, "M              | Toggle Menu");
	mlx_string_put(env->mlx_ptr, env->win_ptr,
			100, 700, 0xD8A4F9, "Change Bottom Color");
	mlx_string_put(env->mlx_ptr, env->win_ptr,
			(env->width / 2) - 100, 700, 0xD8A4F9, "Change Middle Color");
}
