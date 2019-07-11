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

void	gradients(t_env *env, int sl, int z) {
	int		i;
	float	Rres;
	float	Gres;
	float	Bres;

	i = 0;
	Rres = 0;
	Gres = 0;
	Bres = 0;
	if ((env->R1 < env->R2) || (env->R1 > env->R2))
		Rres = (env->R2 - env->R1) / (sl + 1);
	if ((env->G1 < env->G2) || (env->G1 > env->G2))
		Gres = (env->G2 - env->G1) / (sl + 1);
	if ((env->B1 < env->B2) || (env->B1 > env->B2))
		Bres = (env->B2 - env->B1) / (sl + 1);
//	while (i < z)
//	{
		env->R += Rres;
		env->G += Gres;
		env->B += Bres;
//		i++;
//	}
	printf("%d\n", z);
	//printf("res = %f\nr1 : %f\nr2 : %f\nr : %f\n\n", res,env->G1, env->G2, env->G);
}

void	fill_pixel(char *img_str, t_seg *seg, t_env *env, int sl)
{
	int pos;
	int i;
	//printf("1 %d\n2 %d\n", seg->z1, seg->z2);
	gradients(env, sl, (seg->z2 - seg->z1));
	pos = 0;
	pos = (pos + 4 * env->width) * seg->y1;
	pos += 4 * seg->x1;
	img_str[pos] = (char)env->B;
	img_str[pos + 1] = (char)env->G;
	img_str[pos + 2] = (char)env->R;
	img_str[pos + 3] = (char)0;
}
