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

int		map_draw(t_env *env)
{
	t_seg seg1;

	t_vec vec1;
	t_vec vec2;
	t_vec vec3;
	t_vec vec4;
	t_vec vec5;
	t_vec vec6;
	t_vec vec7;
	t_vec vec8;

	vec1 = project(&(env->vec1));
	vec2 = project(&(env->vec2));
	vec3 = project(&(env->vec3));
	vec4 = project(&(env->vec4));
	vec5 = project(&(env->vec5));
	vec6 = project(&(env->vec6));
	vec7 = project(&(env->vec7));
	vec8 = project(&(env->vec8));
	vec1 = vec_mult(&vec1, 800);
	vec2 = vec_mult(&vec2, 800);
	vec3 = vec_mult(&vec3, 800);
	vec4 = vec_mult(&vec4, 800);
	vec5 = vec_mult(&vec5, 800);
	vec6 = vec_mult(&vec6, 800);
	vec7 = vec_mult(&vec7, 800);
	vec8 = vec_mult(&vec8, 800);
	vec1 = translate(&vec1, env->width/2, env->height/2, 0);
	vec2 = translate(&vec2, env->width/2, env->height/2, 0);
	vec3 = translate(&vec3, env->width/2, env->height/2, 0);
	vec4 = translate(&vec4, env->width/2, env->height/2, 0);
	vec5 = translate(&vec5, env->width/2, env->height/2, 0);
	vec6 = translate(&vec6, env->width/2, env->height/2, 0);
	vec7 = translate(&vec7, env->width/2, env->height/2, 0);
	vec8 = translate(&vec8, env->width/2, env->height/2, 0);
	seg1.x1 = (int)(vec1.x);
	seg1.y1 = (int)(vec1.y);
	seg1.x2 = (int)(vec2.x);
	seg1.y2 = (int)(vec2.y);

	line_tracer(&seg1, env);

	seg1.x1 = (int)(vec2.x);
	seg1.y1 = (int)(vec2.y);
	seg1.x2 = (int)(vec3.x);
	seg1.y2 = (int)(vec3.y);

	line_tracer(&seg1, env);

	seg1.x1 = (int)(vec3.x);
	seg1.y1 = (int)(vec3.y);
	seg1.x2 = (int)(vec4.x);
	seg1.y2 = (int)(vec4.y);

	line_tracer(&seg1, env);

	seg1.x1 = (int)(vec4.x);
	seg1.y1 = (int)(vec4.y);
	seg1.x2 = (int)(vec1.x);
	seg1.y2 = (int)(vec1.y);

	line_tracer(&seg1, env);

	seg1.x1 = (int)(vec5.x);
	seg1.y1 = (int)(vec5.y);
	seg1.x2 = (int)(vec6.x);
	seg1.y2 = (int)(vec6.y);

	line_tracer(&seg1, env);

	seg1.x1 = (int)(vec6.x);
	seg1.y1 = (int)(vec6.y);
	seg1.x2 = (int)(vec7.x);
	seg1.y2 = (int)(vec7.y);

	line_tracer(&seg1, env);

	seg1.x1 = (int)(vec7.x);
	seg1.y1 = (int)(vec7.y);
	seg1.x2 = (int)(vec8.x);
	seg1.y2 = (int)(vec8.y);

	line_tracer(&seg1, env);

	seg1.x1 = (int)(vec8.x);
	seg1.y1 = (int)(vec8.y);
	seg1.x2 = (int)(vec5.x);
	seg1.y2 = (int)(vec5.y);

	line_tracer(&seg1, env);

	seg1.x1 = (int)(vec1.x);
	seg1.y1 = (int)(vec1.y);
	seg1.x2 = (int)(vec5.x);
	seg1.y2 = (int)(vec5.y);

	line_tracer(&seg1, env);

	seg1.x1 = (int)(vec2.x);
	seg1.y1 = (int)(vec2.y);
	seg1.x2 = (int)(vec6.x);
	seg1.y2 = (int)(vec6.y);

	line_tracer(&seg1, env);

	seg1.x1 = (int)(vec3.x);
	seg1.y1 = (int)(vec3.y);
	seg1.x2 = (int)(vec7.x);
	seg1.y2 = (int)(vec7.y);

	line_tracer(&seg1, env);

	seg1.x1 = (int)(vec4.x);
	seg1.y1 = (int)(vec4.y);
	seg1.x2 = (int)(vec8.x);
	seg1.y2 = (int)(vec8.y);

	line_tracer(&seg1, env);

	return 0;
}

int		render(t_env *env)
{




	rotate_z(&env->vec1);
	rotate_z(&env->vec2);
	rotate_z(&env->vec3);
	rotate_z(&env->vec4);
	rotate_z(&env->vec5);
	rotate_z(&env->vec6);
	rotate_z(&env->vec7);
	rotate_z(&env->vec8);
	rotate_x(&env->vec1);
	rotate_x(&env->vec2);
	rotate_x(&env->vec3);
	rotate_x(&env->vec4);
	rotate_x(&env->vec5);
	rotate_x(&env->vec6);
	rotate_x(&env->vec7);
	rotate_x(&env->vec8);
	rotate_y(&env->vec1);
	rotate_y(&env->vec2);
	rotate_y(&env->vec3);
	rotate_y(&env->vec4);
	rotate_y(&env->vec5);
	rotate_y(&env->vec6);
	rotate_y(&env->vec7);
	rotate_y(&env->vec8);
	printf("x %f y %f z %f\n",(env->vec1).x, (env->vec1).y, (env->vec1).z);
	printf("x %f y %f z %f\n",(env->vec5).x, (env->vec5).y, (env->vec5).z);


	map_draw(env);

	return (0);
}
