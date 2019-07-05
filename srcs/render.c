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

void	trace_square(t_vec *vec1, t_vec *vec2, t_vec *vec3, t_vec *vec4, t_win *win)
{
	t_coor coor1;
	t_coor coor2;
	t_coor coor3;
	t_coor coor4;

	coor1.x1 = vec1->x;
	coor1.y1 = vec1->y;
	coor1.x2 = vec2->x;
	coor1.y2 = vec2->y;

	coor2.x1 = vec2->x;
	coor2.y1 = vec2->y;
	coor2.x2 = vec3->x;
	coor2.y2 = vec3->y;

	coor3.x1 = vec3->x;
	coor3.y1 = vec3->y;
	coor3.x2 = vec4->x;
	coor3.y2 = vec4->y;

	coor4.x1 = vec4->x;
	coor4.y1 = vec4->y;
	coor4.x2 = vec1->x;
	coor4.y2 = vec1->y;

//	printf("x1 %d y1 %d x2 %d y2 %d \n", coor1.x1, coor1.y1, coor1.x2, coor1.y2);

	line_tracer(&coor1, win);
	line_tracer(&coor2, win);
	line_tracer(&coor3, win);
	line_tracer(&coor4, win);
	return;
}

int		render(t_win *win)
{
	t_mat projection;
	t_vec vec1;
	t_vec vec2;
	t_vec vec3;
	t_vec vec4;
	int i;

	i = 0;
	projection.x[0] = 1;
	projection.x[1] = 0;
	projection.x[2] = 0;

	projection.y[0] = 0;
	projection.y[1] = 1;
	projection.y[2] = 0;

	projection.z[0] = 0;
	projection.z[1] = 0;
	projection.z[2] = 0;

	vec1.x = 500;
	vec1.y = 500;
	vec1.z = 400;

	vec2.x = 800;
	vec2.y = 500;
	vec2.z = 400;

	vec3.x = 800;
	vec3.y = 800;
	vec3.z = 400;

	vec4.x = 500;
	vec4.y = 800;
	vec4.z = 400;

	vec1 = mat_mult(&vec1, projection);
	vec2 = mat_mult(&vec2, projection);
	vec3 = mat_mult(&vec3, projection);
	vec4 = mat_mult(&vec4, projection);

	while (i < 50)
	{
		rotate_z(&vec1);
		rotate_z(&vec2);
		rotate_z(&vec3);
		rotate_z(&vec4);
		i++;
	}
	//printf("x = %f y = %f z = %f \n", vec1->x, vec1->y, vec1->z);
	trace_square(&vec1, &vec2, &vec3, &vec4, win);
	return (0);
}
