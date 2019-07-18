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
		env->r[env->menux + 1] = 153;
		env->g[env->menux + 1] = 0;
		env->b[env->menux + 1] = 255;
	}
	else if (env->menuy == 7)
	{
		env->r[env->menux + 1] = 255;
		env->g[env->menux + 1] = 255;
		env->b[env->menux + 1] = 0;
	}
	else if (env->menuy == 8)
	{
		env->r[env->menux + 1] = 253;
		env->g[env->menux + 1] = 14;
		env->b[env->menux + 1] = 225;
	}
}

void	menu_color2(t_env *env)
{
	if (env->menuy == 3)
	{
		env->r[env->menux + 1] = 0;
		env->g[env->menux + 1] = 0;
		env->b[env->menux + 1] = 0;
	}
	else if (env->menuy == 4)
	{
		env->r[env->menux + 1] = 255;
		env->g[env->menux + 1] = 255;
		env->b[env->menux + 1] = 255;
	}
	else if (env->menuy == 5)
	{
		env->r[env->menux + 1] = 255;
		env->g[env->menux + 1] = 153;
		env->b[env->menux + 1] = 0;
	}
}

void	menu_color(t_env *env)
{
	if (env->menuy == 0)
	{
		env->r[env->menux + 1] = 255;
		env->g[env->menux + 1] = 0;
		env->b[env->menux + 1] = 0;
	}
	else if (env->menuy == 1)
	{
		env->r[env->menux + 1] = 0;
		env->g[env->menux + 1] = 255;
		env->b[env->menux + 1] = 0;
	}
	else if (env->menuy == 2)
	{
		env->r[env->menux + 1] = 0;
		env->g[env->menux + 1] = 0;
		env->b[env->menux + 1] = 255;
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
	else
		x = (env->width / 2) - 125;
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
