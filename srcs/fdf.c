/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fdf.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: brey-gal <brey-gal@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/03 20:41:09 by brey-gal     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/03 20:41:09 by brey-gal    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		deal_key(int key, t_env *env)
{

	if (key == 53)
	{
		env_del(env);
		exit(1);
	}
	mlx_clear_window(env->mlx_ptr, env->win_ptr);
	render(env);
	return 0;
}

int		fdf(t_env *env)
{
	int i = 0;

	(env->vec1).x = 0;
	(env->vec1).y = 0;
	(env->vec1).z = 0;

	(env->vec2).x = 0;
	(env->vec2).y = 0;
	(env->vec2).z = 0;

	(env->vec3).x = 0;
	(env->vec3).y = 0;
	(env->vec3).z = 0;

	(env->vec4).x = 0;
	(env->vec4).y = 0;
	(env->vec4).z = 0;

	(env->vec5).x = 0;
	(env->vec5).y = 0;
	(env->vec5).z = 0;

	(env->vec6).x = 0;
	(env->vec6).y = 0;
	(env->vec6).z = 0;

	(env->vec7).x = 0;
	(env->vec7).y = 0;
	(env->vec7).z = 0;

	(env->vec8).x = 0;
	(env->vec8).y = 0;
	(env->vec8).z = 0;

	env->width = 2560;
	env->height = 1315;
	setup(env);
	env->mlx_ptr = mlx_init();
	env->win_ptr = mlx_new_window(env->mlx_ptr, env->width, env->height, "FdF");
	env->vec = vec_new();
	map_to_struct(&env->map, env->vec);
	vec_del(env->vec);
	mlx_key_hook(env->win_ptr, deal_key, env);
	mlx_loop(env->mlx_ptr);
	return (0);
}
