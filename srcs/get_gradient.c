/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_gradient.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: brey-gal <brey-gal@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/12 02:51:21 by brey-gal     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/12 02:51:21 by brey-gal    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	get_gradient(t_env *env, int sl, t_seg *seg)
{
	float	percent;

	env->sl = sl;
	percent = 1;
	env->Rres = 0;
	env->Gres = 0;
	env->Bres = 0;
	if (env->R[1] != env->R[2])
		env->Rres = (env->R[2] - env->R[1]) / (sl + 1);
	if (env->G[1] != env->G[2])
		env->Gres = (env->G[2] - env->G[1]) / (sl + 1);
	if (env->B[1] != env->B[2])
		env->Bres = (env->B[2] - env->B[1]) / (sl + 1);
	if (env->z1 != 0)
	{
		if (env->z1 >= 0)
			percent = env->z1 / env->map.zmax;
		else
			percent = env->z1 / env->map.zmin;
		env->R[0] += (env->R[2] - env->R[1]) * percent;
		env->G[0] += (env->G[2] - env->G[1]) * percent;
		env->B[0] += (env->B[2] - env->B[1]) * percent;
	}
	if (env->z1 != env->z2)
	{
		if (env->z1 >= 0 && env->z2 >= 0)
		{
			if (env->z2 > env->z1)
				percent = (env->z2 - env->z1) / env->map.zmax;
			else
				percent = (env->z1 - env->z2) / env->map.zmax;
		}
		else if (env->z1 <= 0 && env->z2 <= 0)
		{
			if (env->z2 > env->z1)
				percent = (env->z2 - env->z1) / env->map.zmin;
			else
				percent = (env->z1 - env->z2) / env->map.zmin;
		}
		else
		{
			if (env->R[1] != env->R[2])
				env->Rres = (env->R[1] - env->R[2]) / (sl / ((fabs(env->z1) + fabs(env->z2)) / fabs(env->z1)));
			if (env->G[1] != env->G[2])
				env->Gres = (env->G[1] - env->G[2]) / (sl / ((fabs(env->z1) + fabs(env->z2)) / fabs(env->z1)));
			if (env->B[1] != env->B[2])
				env->Bres = (env->B[1] - env->B[2]) / (sl / ((fabs(env->z1) + fabs(env->z2)) / fabs(env->z1)));
		}
		env->Rres *= percent;
		env->Gres *= percent;
		env->Bres *= percent;
	}
}