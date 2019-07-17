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

void	anglecheck(t_env *env)
{
	if (env->angle_x > 32)
		env->angle_x = -31;
	if (env->angle_y > 32)
		env->angle_y = -31;
	if (env->angle_z > 32)
		env->angle_z = -31;
	if (env->angle_x < -31)
		env->angle_x = 31;
	if (env->angle_y < -31)
		env->angle_y = 31;
	if (env->angle_z < -31)
		env->angle_z = 31;
}

void	anglekey(int key, t_env *env)
{
	if (key == 123)
		env->angle_y -= 1;
	if (key == 126)
		env->angle_x += 1;
	if (key == 124)
		env->angle_y += 1;
	if (key == 125)
		env->angle_x -= 1;
	if (key == 116)
		env->angle_z += 1;
	if (key == 121)
		env->angle_z -= 1;
	if (key == 2)
	{
		env->angle_x = 0;
		env->angle_y = 0;
		env->angle_z = 0;
	}
	anglecheck(env);
	if (key == 3)
		env->iso = 1;
	else
		env->iso = 0;
}

int		deal_key(int key, t_env *env)
{
	int i = 0;

	if (key == 53)
	{
		env_del(env);
		exit(1);
	}
	if (key == 2 || key == 3 || (key > 115 && key < 127))
		anglekey(key, env);
	if (key == 31)
		env->alt += 0.1;
	if (key == 35)
		env->alt -= 0.1;
	if (key == 69)
		env->zoom += 5;
	if (key == 78)
		env->zoom -= 5;
	render(env->vec, env);
	return 0;
}

int		deal_mouse(int button, int x, int y, t_env *env)
{
	if (button == 4)
		env->zoom += 5;
	if (button == 5)
		env->zoom -= 5;
	mlx_clear_window(env->mlx_ptr, env->win_ptr);
	render(env->vec, env);
	return 0;
}

int		fdf(t_env *env, t_vec *vec)
{
	int i = 0;
	int ret;

	env->vec = vec_new();
	env->width = 2560;
	env->height = 1315;
	env->zoom = 10;
	env->alt = 0.5;
	env->angle_x = 0;
	env->angle_y = 0;
	env->angle_z = 0;
	env->iso = 0;
	env->mlx_ptr = mlx_init();
	env->win_ptr = mlx_new_window(env->mlx_ptr, env->width, env->height, "FdF");
	env->img_pptr = mlx_new_image(env->mlx_ptr, env->width, env->height);
	map_to_struct(&env->map, env->vec);
	render(env->vec, env);
	mlx_key_hook(env->win_ptr, deal_key, env);
	mlx_mouse_hook(env->win_ptr, deal_mouse, env);
	mlx_loop(env->mlx_ptr);
	return (0);
}
