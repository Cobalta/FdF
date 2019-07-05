/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   matrix_op.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ebourgeo <ebourgeo@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/04 01:54:56 by ebourgeo     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/04 01:54:56 by ebourgeo    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_vec	mtx_mult(t_vec *vec, t_mtx mtx)
{
	t_vec res;

	res.x = vec->x * mtx.x[0] + vec->y * mtx.y[0] + vec->z * mtx.z[0];
	res.y = vec->x * mtx.x[1] + vec->y * mtx.y[1] + vec->z * mtx.z[1];
	res.z = vec->x * mtx.x[2] + vec->y * mtx.y[2] + vec->z * mtx.z[2];
	return (res);
}

t_vec	project(t_vec *vec)
{
	t_mtx projection;
	int distance;

	distance = 2;
	projection.x[0] = (1 / (distance - vec->z));
	projection.x[1] = 0;
	projection.x[2] = 0;

	projection.y[0] = 0;
	projection.y[1] = (1 / (distance - vec->z));
	projection.y[2] = 0;

	projection.z[0] = 0;
	projection.z[1] = 0;
	projection.z[2] = 0;

	return ((mtx_mult(vec, projection)));
}

t_vec vec_mult(t_vec *vec, int mult)
{
	t_vec res;

	res.x = vec->x * mult;
	res.y = vec->y * mult;
	res.z = vec->z * mult;

	return (res);
}

t_vec translate(t_vec *vec, int x, int y, int z)
{
	t_vec res;

	res.x = vec->x + x;
	res.y = vec->y + y;
	res.z = vec->z + z;
	return (res);
}

t_vec *rotate_x(t_vec *vec)
{
	t_mtx rot;
	float angle;

	angle = 0.05;
	rot.x[0] = 1;
	rot.y[0] = 0;
	rot.z[0] = 0;
	rot.x[1] = 0;
	rot.y[1] = cos(angle);
	rot.z[1] = -sin(angle);
	rot.x[2] = 0;
	rot.y[2] = sin(angle);
	rot.z[2] = cos(angle);

	*vec = mtx_mult(vec, rot);
	return (vec);
}

t_vec *rotate_y(t_vec *vec)
{
	t_mtx rot;
	float angle;

	angle = 0.01;
	rot.x[0] = cos(angle);
	rot.y[0] = 0;
	rot.z[0] = sin(angle);
	rot.x[1] = 0;
	rot.y[1] = 1;
	rot.z[1] = 0;
	rot.x[2] = -sin(angle);
	rot.y[2] = 0;
	rot.z[2] = cos(angle);

	*vec = mtx_mult(vec, rot);
	return (vec);
}

t_vec *rotate_z(t_vec *vec)
{
	t_mtx rot;
	float angle;

	angle = 0.00;
	rot.x[0] = cos(angle);
	rot.y[0] = -sin(angle);
	rot.z[0] = 0;
	rot.x[1] = sin(angle);
	rot.y[1] = cos(angle);
	rot.z[1] = 0;
	rot.x[2] = 0;
	rot.y[2] = 0;
	rot.z[2] = 1;

	*vec = mtx_mult(vec, rot);
	return (vec);
}