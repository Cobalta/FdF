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
		env->angle_y -= 10;
	if (key == 126)
		env->angle_x += 10;
	if (key == 124)
		env->angle_y += 10;
	if (key == 125)
		env->angle_x -= 10;
	if (key == 116)
		env->angle_z += 10;
	if (key == 121)
		env->angle_z -= 10;
	if (key == 69)
		env->zoom += 5;
	if (key == 78)
		env->zoom -= 5;
	if (key == 2)
	{
		env->angle_x = 0;
		env->angle_y = 0;
		env->angle_z = 0;
	}
	if (key == 3)
	{
		env->angle_x = 35;
		env->angle_y = 30;
		env->angle_z = -61;
	}
	env->slmax = (env->zoom * env->map.zmax)/2;
//	while (env->angle_x > (2 * PI))
//		env->angle_x = env->angle_x - (2 * PI);
//	while (env->angle_y > (2 * PI))
//		env->angle_y = env->angle_y - (2 * PI);
//	while (env->angle_z > (2 * PI))
//		env->angle_z = env->angle_z - (2 * PI);
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
	env->zoom = 30;
	env->angle_x = 0;
	env->angle_y = 0;
	env->angle_z = 0;
	env->mlx_ptr = mlx_init();
	env->win_ptr = mlx_new_window(env->mlx_ptr, env->width, env->height, "FdF");
	env->img_pptr = mlx_new_image(env->mlx_ptr, env->width, env->height);
	map_to_struct(&env->map, env->vec);
	env->slmax = env->map.zmax * env->zoom;
	mlx_key_hook(env->win_ptr, deal_key, env);
	mlx_mouse_hook(env->win_ptr, deal_mouse, env);
	mlx_loop(env->mlx_ptr);
	return (0);
}
