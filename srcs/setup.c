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

void	setup(t_env *env)
{

	(env->vec1).x = -0.5;
	(env->vec1).y = -0.5;
	(env->vec1).z = -0.5;

	(env->vec2).x = 0.5;
	(env->vec2).y = -0.5;
	(env->vec2).z = -0.5;

	(env->vec3).x = 0.5;
	(env->vec3).y = 0.5;
	(env->vec3).z = -0.5;

	(env->vec4).x = -0.5;
	(env->vec4).y = 0.5;
	(env->vec4).z = -0.5;

	(env->vec5).x = -0.5;
	(env->vec5).y = -0.5;
	(env->vec5).z = 0.5;

	(env->vec6).x = 0.5;
	(env->vec6).y = -0.5;
	(env->vec6).z = 0.5;

	(env->vec7).x = 0.5;
	(env->vec7).y = 0.5;
	(env->vec7).z = 0.5;

	(env->vec8).x = -0.5;
	(env->vec8).y = 0.5;
	(env->vec8).z = 0.5;

	return;
}