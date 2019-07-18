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

	percent = 1;
	env->r_res = 0;
	env->g_res = 0;
	env->b_res = 0;
	if (env->r[1] != env->r[2])
		env->r_res = (env->r[2] - env->r[1]) / (sl + 1);

	if (env->g[1] != env->g[2])
		env->g_res = (env->g[2] - env->g[1]) / (sl + 1);

	if (env->b[1] != env->b[2])
		env->b_res = (env->b[2] - env->b[1]) / (sl + 1);

	if (env->z1 != 0)
	{
		//printf("::%f\n", env->g[0]);

		percent = env->z1 / env->map.zmax;
		env->r[0] += (env->r[2] - env->r[1]) * percent;

		//printf("env->r_res : %f\nenv->z1 : %f\nenv->r[0] : %f\npercent : %f\nsl : %d\n\n",env->r_res,env->z1,env->r[0],percent,sl);

		percent = env->z1 / env->map.zmax;
		env->g[0] += ((env->g[2] - env->g[1]) * percent);


		percent = env->z1 / env->map.zmax;
		env->b[0] += (env->b[2] - env->b[1]) * percent;
	}
	if (env->z1 != env->z2)
	{
		if (env->z2 > env->z1)
			percent = (env->z2 - env->z1) / env->map.zmax;
		else
			percent = (env->z1 - env->z2) / env->map.zmax;
		env->r_res *= percent;
		env->g_res *= percent;
		env->b_res *= percent;
	}
}