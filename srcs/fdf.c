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
	int i = 0;
	if (key == 53)
	{
		env_del(env);
		exit(1);
	}
	mlx_clear_window(env->mlx_ptr, env->win_ptr);
	if (key == 123)
		env->angle_x += PI / 30;
	if (key == 126)
		env->angle_y += PI / 30;
	if (key == 124)
		env->angle_z += PI / 30;
	if (key == 2)
	{
		env->angle_x += PI / 30;
		env->angle_y += PI / 30;
		env->angle_z += PI / 30;
	}

	while (env->angle_x > (2 * PI))
		env->angle_x = env->angle_x - (2 * PI);
	while (env->angle_y > (2 * PI))
		env->angle_y = env->angle_y - (2 * PI);
	while (env->angle_z > (2 * PI))
		env->angle_z = env->angle_z - (2 * PI);
	render(env->vec, env);
	return 0;
}

int		deal_mouse(int button, int x, int y, t_env *env)
{
	//printf("key = %d\n", button);
	mlx_clear_window(env->mlx_ptr, env->win_ptr);

	return 0;
}

int		fdf(t_env *env, t_vec *vec)
{
	int i = 0;
	int ret;

	env->vec = vec_new();
	env->width = 2560;
	env->height = 1315;
	env->angle_x = 0;
	env->angle_y = 0;
	env->angle_z = 0;
	env->mlx_ptr = mlx_init();
	env->win_ptr = mlx_new_window(env->mlx_ptr, env->width, env->height, "FdF");
	map_to_struct(&env->map, env->vec);
	mlx_key_hook(env->win_ptr, deal_key, env);
	mlx_mouse_hook(env->win_ptr, deal_mouse, env);
	mlx_loop(env->mlx_ptr);
	return (0);
}
