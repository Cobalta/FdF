/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   menu.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ebourgeo <ebourgeo@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/17 00:24:39 by ebourgeo     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/17 00:24:39 by ebourgeo    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	text_display(t_env *env)
{
	displaytext(env);
	displaytext2(env);
	displaytext3(env);
	displaytext4(env);
}

void	menu_color3(t_env *env)
{
	if (env->menuy == 6)
	{
		env->R[env->menux] = 153;
		env->G[env->menux] = 0;
		env->B[env->menux] = 255;
	}
	else if (env->menuy == 7)
	{
		env->R[env->menux] = 255;
		env->G[env->menux] = 255;
		env->B[env->menux] = 0;
	}
	else if (env->menuy == 8)
	{
		env->R[env->menux] = 253;
		env->G[env->menux] = 14;
		env->B[env->menux] = 225;
	}
}

void	menu_color2(t_env *env)
{
	if (env->menuy == 3)
	{
		env->R[env->menux] = 0;
		env->G[env->menux] = 0;
		env->B[env->menux] = 0;
	}
	else if (env->menuy == 4)
	{
		env->R[env->menux] = 255;
		env->G[env->menux] = 255;
		env->B[env->menux] = 255;
	}
	else if (env->menuy == 5)
	{
		env->R[env->menux] = 255;
		env->G[env->menux] = 153;
		env->B[env->menux] = 0;
	}
}

void	menu_color(t_env *env)
{
	if (env->menuy == 0)
	{
		env->R[env->menux] = 255;
		env->G[env->menux] = 0;
		env->B[env->menux] = 0;
	}
	else if (env->menuy == 1)
	{
		env->R[env->menux] = 0;
		env->G[env->menux] = 255;
		env->B[env->menux] = 0;
	}
	else if (env->menuy == 2)
	{
		env->R[env->menux] = 0;
		env->G[env->menux] = 0;
		env->B[env->menux] = 255;
	}
	menu_color2(env);
	menu_color3(env);
}

void	display_menu(int key, t_env *env)
{
	int x;

	mlx_clear_window(env->mlx_ptr, env->win_ptr);
	text_display(env);
	if (key == 123 && env->menux > 0)
		env->menux--;
	if (key == 124 && env->menux < 2)
		env->menux++;
	if (key == 126 && env->menuy > 0)
		env->menuy--;
	if (key == 125 && env->menuy < 8)
		env->menuy++;
	if (env->menux == 0)
		x = 75;
	else if (env->menux == 1)
		x = (env->width / 2) - 125;
	else if (env->menux == 2)
		x = env->width - 525;
	if (key == 36)
	{
		mlx_string_put(env->mlx_ptr, env->win_ptr,
				x, 750 + (env->menuy * 50), 0xFFFFFF, "O");
		menu_color(env);
	}
	else
		mlx_string_put(env->mlx_ptr, env->win_ptr,
				x, 750 + (env->menuy * 50), 0xFFFFFF, "X");
}
