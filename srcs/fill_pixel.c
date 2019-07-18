/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fill_pixel.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: brey-gal <brey-gal@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/10 03:34:40 by brey-gal     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/10 03:34:40 by brey-gal    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	change_color(t_env *env, char sign)
{
	if (sign == '+')
	{
		env->r[0] += env->r_res;
		env->g[0] += env->g_res;
		env->b[0] += env->b_res;
	}
	else if (sign == '-')
	{
		env->r[0] -= env->r_res;
		env->g[0] -= env->g_res;
		env->b[0] -= env->b_res;
	}
}

void	gradients(t_env *env, t_seg *seg)
{
	int		i;
	int		z;

	i = 0;
	z = 0;
	if ((env->z1 < 0 && env->z2 > 0) || (env->z1 > 0 && env->z2 < 0))
	{
		if (env->r[0] <= env->r[1] + 5 && env->r[0] >= env->r[1] - 5)
			env->r_res = (env->r[2] - env->r[1]) / (env->sl / ((fabs(env->z1)
					+ fabs(env->z2)) / fabs(env->z2)));
		if (env->g[0] <= env->g[1] + 5 && env->g[0] >= env->g[1] - 5)
			env->g_res = (env->g[2] - env->g[1]) / (env->sl / ((fabs(env->z1)
					+ fabs(env->z2)) / fabs(env->z2)));
		if (env->b[0] <= env->b[1] + 5 && env->b[0] >= env->b[1] - 5)
			env->b_res = (env->b[2] - env->b[1]) / (env->sl / ((fabs(env->z1)
					+ fabs(env->z2)) / fabs(env->z2)));
		change_color(env, '+');
	}
	else if (env->z1 < env->z2)
		change_color(env, '+');
	else if (env->z1 > env->z2)
		change_color(env, '-');
}

void	fill_pixel(char *img_str, t_seg *seg, t_env *env)
{
	int pos;
	int i;

	gradients(env, seg);
	pos = 0;
	pos = (pos + 4 * env->width) * seg->y1;
	pos += 4 * seg->x1;
	if (seg->y1 >= 0 && seg->y1 < env->height && seg->x1 > 0
		&& seg->x1 < env->width)
	{
		img_str[pos] = (char)env->b[0];
		img_str[pos + 1] = (char)env->g[0];
		img_str[pos + 2] = (char)env->r[0];
		img_str[pos + 3] = (char)0;
	}
}
