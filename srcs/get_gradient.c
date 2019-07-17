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

//void	get_gradient(t_env *env, int sl, t_seg *seg)
//{
//	float	percent;
//
//	percent = 1;
//	env->Rres = 0;
//	env->Gres = 0;
//	env->Bres = 0;
//	if (env->R1 != env->R2)
//		env->Rres = (env->R2 - env->R1) / (sl + 1);
//
//	if (env->G1 != env->G2)
//		env->Gres = (env->G2 - env->G1) / (sl + 1);
//
//	if (env->B1 != env->B2)
//		env->Bres = (env->B2 - env->B1) / (sl + 1);
//
//	if (env->z1 != 0)
//	{
//		//printf("::%f\n", env->G);
//
//		percent = env->z1 / env->map.zmax;
//		env->R += (env->R2 - env->R1) * percent;
//
//		//printf("env->Rres : %f\nenv->z1 : %f\nenv->R : %f\npercent : %f\nsl : %d\n\n",env->Rres,env->z1,env->R,percent,sl);
//
//		percent = env->z1 / env->map.zmax;
//		env->G += ((env->G2 - env->G1) * percent);
//
//
//		percent = env->z1 / env->map.zmax;
//		env->B += (env->B2 - env->B1) * percent;
//	}
//	if (env->z1 != env->z2)
//	{
//		if (env->z2 > env->z1)
//			percent = (env->z2 - env->z1) / env->map.zmax;
//		else
//			percent = (env->z1 - env->z2) / env->map.zmax;
//		env->Rres *= percent;
//		env->Gres *= percent;
//		env->Bres *= percent;
//	}
//}

void	get_gradient(t_env *env, int sl, t_seg *seg)
{
	float	percent;

	env->sl = sl;
	percent = 1;
	env->Rres = 0;
	env->Gres = 0;
	env->Bres = 0;
	if (env->R1 != env->R2)
		env->Rres = (env->R2 - env->R1) / (sl + 1);

	if (env->G1 != env->G2)
		env->Gres = (env->G2 - env->G1) / (sl + 1);

	if (env->B1 != env->B2)
		env->Bres = (env->B2 - env->B1) / (sl + 1);
	if (env->z1 != 0)
	{
		if (env->z1 >= 0)
			percent = env->z1 / env->map.zmax;
		else
			percent = env->z1 / env->map.zmin;
		env->R += (env->R2 - env->R1) * percent;
		env->G += (env->G2 - env->G1) * percent;
		env->B += (env->B2 - env->B1) * percent;
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
			if (env->R1 != env->R2)
				env->Rres = (env->R1 - env->R2) / (sl / ((fabs(env->z1) + fabs(env->z2)) / fabs(env->z1)));
			if (env->G1 != env->G2)
				env->Gres = (env->G1 - env->G2) / (sl / ((fabs(env->z1) + fabs(env->z2)) / fabs(env->z1)));
			if (env->B1 != env->B2)
				env->Bres = (env->B1 - env->B2) / (sl / ((fabs(env->z1) + fabs(env->z2)) / fabs(env->z1)));
		}
		env->Rres *= percent;
		env->Gres *= percent;
		env->Bres *= percent;
	}
}