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

void	gradients(t_env *env, t_seg *seg) {
	int		i;
	int		z;

	i = 0;
	z = 0;
	if ((env->z1 < 0 && env->z2 > 0) ||	(env->z1 > 0 && env->z2 < 0))
	{
		if (env->R[0] <= env->R[1] + 5 && env->R[0] >= env->R[1] - 5)
			env->Rres = (env->R[2] - env->R[1]) / (env->sl / ((fabs(env->z1) + fabs(env->z2)) / fabs(env->z2)));
		if (env->G[0] <= env->G[1] + 5 && env->G[0] >= env->G[1] - 5)
			env->Gres = (env->G[2] - env->G[1]) / (env->sl / ((fabs(env->z1) + fabs(env->z2)) / fabs(env->z2)));
		if (env->B[0] <= env->B[1] + 5 && env->B[0] >= env->B[1] - 5)
			env->Bres = (env->B[2] - env->B[1]) / (env->sl / ((fabs(env->z1) + fabs(env->z2)) / fabs(env->z2)));
		env->R[0] += env->Rres;
		env->G[0] += env->Gres;
		env->B[0] += env->Bres;
	}
	else if (env->z1 < env->z2)
	{
		env->R[0] += env->Rres;
		env->G[0] += env->Gres;
		env->B[0] += env->Bres;
	}
	else if (env->z1 > env->z2)
	{
		env->R[0] -= env->Rres;
		env->G[0] -= env->Gres;
		env->B[0] -= env->Bres;
	}
}

void	fill_pixel(char *img_str, t_seg *seg, t_env *env)
{
	int pos;
	int i;
	gradients(env, seg);
	pos = 0;
	pos = (pos + 4 * env->width) * seg->y1;
	pos += 4 * seg->x1;
	img_str[pos] = (char)env->B[0];
	img_str[pos + 1] = (char)env->G[0];
	img_str[pos + 2] = (char)env->R[0];
	img_str[pos + 3] = (char)0;
}
