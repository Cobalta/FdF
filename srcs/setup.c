/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   setup.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ebourgeo <ebourgeo@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/04 21:32:29 by ebourgeo     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/04 21:32:29 by ebourgeo    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	setup_colors(t_env *env)
{
	env->r[0] = env->r[1];
	env->g[0] = env->g[1];
	env->b[0] = env->b[1];
}

void	setup(t_env *env)
{
	env->r[0] = 255;
	env->r[1] = 255;
	env->r[2] = 0;
	env->g[0] = 0;
	env->g[1] = 0;
	env->g[2] = 0;
	env->b[0] = 0;
	env->b[1] = 0;
	env->b[2] = 255;
	env->menux = 0;
	env->menuy = 0;
	env->pan_x = 0;
	env->pan_y = 0;
	env->vec = vec_new();
	env->width = 2560;
	env->height = 1315;
	env->zoom = 10;
	env->menu = 0;
	env->alt = 0.5;
	env->angle_x = 0;
	env->angle_y = 0;
	env->angle_z = 0;
	env->iso = 0;
	return ;
}
