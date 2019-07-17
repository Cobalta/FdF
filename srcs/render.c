/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   render.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ebourgeo <ebourgeo@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/04 04:07:44 by ebourgeo     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/04 04:07:44 by ebourgeo    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	draw_line(t_vec *vec1, t_vec *vec2, t_env *env)
{
	t_seg seg;

	seg.z1 = (int)(vec1->z1);
	seg.z2 = (int)(vec2->z1);
	vec_mult(vec2, env->zoom);
	translate(vec2, env->width / 2 + env->pan_x, env->height / 2 + env->pan_y, 0);
	if ((vec1->x < env->width && vec1->x > 0)
		&& (vec1->y < env->height && vec1->y > 0))
		if ((vec2->x < env->width && vec2->x > 0)
			&& (vec2->y < env->height && vec2->y > 0))
		{
			seg.x1 = (int)(vec1->x);
			seg.y1 = (int)(vec1->y);
			seg.x2 = (int)(vec2->x);
			seg.y2 = (int)(vec2->y);
			line_tracer(&seg, env);
		}
}

void	rotater(t_vec *vec1, t_vec *vec2, t_vec *vec3, t_env *env)
{
	rotate_y(vec1, env->angle_y);
	rotate_x(vec1, env->angle_x);
	rotate_z(vec1, env->angle_z);
	if (vec2 != NULL)
	{
		rotate_y(vec2, env->angle_y);
		rotate_x(vec2, env->angle_x);
		rotate_z(vec2, env->angle_z);
	}
	if (vec3 != NULL)
	{
		rotate_y(vec3, env->angle_y);
		rotate_x(vec3, env->angle_x);
		rotate_z(vec3, env->angle_z);
	}
}

void	projecter(t_vec *vec1, t_vec *vec2, t_vec *vec3, t_env *env)
{
	if (env->iso == 1)
		iso(vec1);
	else
		project(vec1);
	if (vec2 != NULL)
	{
		if (env->iso == 1)
			iso(vec2);
		else
			project(vec2);
	}
	if (vec3 != NULL)
	{
		if (env->iso == 1)
			iso(vec3);
		else
			project(vec3);
	}
}

void	map_draw(t_vec *vec, t_env *env)
{
	t_vec vec1;
	t_vec vec2;
	t_vec vec3;

	//printf("x %f y %f z %f\n",env->angle_x, env->angle_y, env->angle_z),fflush(stdout);
	vec1 = vec_cpy(vec);
	vec1.z *= env->alt;
	if (vec->right != NULL)
	{
		vec2 = vec_cpy(vec->right);
		vec2.z *= env->alt;
		env->z2 = vec->right->z;
	}
	if (vec->down != NULL)
	{
		vec3 = vec_cpy(vec->down);
		vec3.z *= env->alt;
	}
	if (env->iso == 0)
		rotater(&vec1, &vec2, &vec3, env);
	projecter(&vec1, &vec2, &vec3, env);
	vec_mult(&vec1, env->zoom);
	translate(&vec1, env->width / 2 + env->pan_x, env->height / 2 + env->pan_y, 0);
	env->z1 = vec->z;
	if (vec->right != NULL)
		draw_line(&vec1, &vec2, env);
	if (vec->down != NULL)
	{
		env->z2 = vec->down->z;
		draw_line(&vec1, &vec3, env);
	}
}


int		render(t_vec *vec, t_env *env)
{
	//printf("B x %f y %f z %f\n",vec->x, vec->y, vec->z),fflush(stdout);
	while (vec->next != NULL)
	{
		//printf("x %f y %f z %f\n",vec->x, vec->y, vec->z),fflush(stdout);
		map_draw(vec->next, env);
		vec = vec->next;
	}
	mlx_clear_window(env->mlx_ptr, env->win_ptr);
	mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->img_pptr, 0, 0);
	mlx_string_put(env->mlx_ptr, env->win_ptr, 50, 100, 0xa020f0, "X");
	mlx_string_put(env->mlx_ptr, env->win_ptr, 100, 100, 0xa020f0, ft_itoa(env->angle_x));
	mlx_string_put(env->mlx_ptr, env->win_ptr, 50, 150, 0xa020f0, "Y");
	mlx_string_put(env->mlx_ptr, env->win_ptr, 100, 150, 0xa020f0, ft_itoa(env->angle_y));
	mlx_string_put(env->mlx_ptr, env->win_ptr, 50, 200, 0xa020f0, "Z");
	mlx_string_put(env->mlx_ptr, env->win_ptr, 100, 200, 0xa020f0, ft_itoa(env->angle_z));
	mlx_destroy_image(env->mlx_ptr, env->img_pptr);
	env->img_pptr = mlx_new_image(env->mlx_ptr, env->width, env->height);
	return (0);
}
