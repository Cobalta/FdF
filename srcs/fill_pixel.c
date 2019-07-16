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
	if (env->z1 < env->z2)
	{
		env->R += env->Rres;
		env->G += env->Gres;
		env->B += env->Bres;
	}
	else if (env->z1 > env->z2)
	{
		env->R -= env->Rres;
		env->G -= env->Gres;
		env->B -= env->Bres;
	}
}

void	fill_pixel(char *img_str, t_seg *seg, t_env *env)
{
	int pos;
	int i;
//	printf("1 %f\n2 %f\n", seg->z1, seg->z2);
	gradients(env, seg);
	pos = 0;
	pos = (pos + 4 * env->width) * seg->y1;
	pos += 4 * seg->x1;
	img_str[pos] = (char)env->B;
	img_str[pos + 1] = (char)env->G;
	img_str[pos + 2] = (char)env->R;
	img_str[pos + 3] = (char)0;
}
