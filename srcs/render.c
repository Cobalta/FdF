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

void	draw_right(t_vec *vec1, t_vec *vec2, t_env *env)
{
	t_seg seg;

	seg.z1 = (int)(vec1->z1);
	seg.z2 = (int)(vec2->z1);
	*vec2 = vec_mult(vec2, env->zoom);
	*vec2 = translate(vec2, env->width/2, env->height/2, 0);
	seg.x1 = (int)(vec1->x);
	seg.y1 = (int)(vec1->y);
	seg.x2 = (int)(vec2->x);
	seg.y2 = (int)(vec2->y);
	line_tracer(&seg, env);
}

void	draw_down(t_vec *vec1, t_vec *vec3, t_env *env)
{
	t_seg seg;

	seg.z1 = (int)(vec1->z1);
	seg.z2 = (int)(vec3->z1);
	*vec3 = vec_mult(vec3, env->zoom);
	*vec3 = translate(vec3, env->width/2, env->height/2, 0);
	seg.x1 = (int)(vec1->x);
	seg.y1 = (int)(vec1->y);
	seg.x2 = (int)(vec3->x);
	seg.y2 = (int)(vec3->y);
	line_tracer(&seg, env);
}

void	map_draw(t_vec *vec, t_env *env)
{
	t_vec vec1;
	t_vec vec2;
	t_vec vec3;
	//printf("x %f y %f z %f\n",env->angle_x, env->angle_y, env->angle_z),fflush(stdout);
	vec1 = rotate_x(vec, env->angle_x);
	vec1.z1 = vec->z;
	vec1 = rotate_y(&vec1, env->angle_y);
	vec1 = rotate_z(&vec1, env->angle_z);
	project(&vec1);
	vec1 = vec_mult(&vec1, env->zoom);
	vec1 = translate(&vec1, env->width/2, env->height/2, 0);
	if (vec->right != NULL)
	{
		vec2 = rotate_x(vec->right, env->angle_x);
		vec2.z1 = vec->right->z;
		vec2 = rotate_y(&vec2, env->angle_y);
		vec2 = rotate_z(&vec2, env->angle_z);
		project(&vec2);
		draw_right(&vec1, &vec2, env);
	}
	if (vec->down != NULL)
	{
		vec3 = rotate_x(vec->down, env->angle_x);
		vec3.z1 = vec->down->z;
		vec3 = rotate_y(&vec3, env->angle_y);
		vec3 = rotate_z(&vec3, env->angle_z);
		project(&vec3);
		draw_down(&vec1, &vec3, env);
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
