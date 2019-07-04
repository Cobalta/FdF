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

t_vec	mat_mult(t_vec *vec, t_mat mat)
{
	t_vec res;

	res.x = vec->x * mat.x[0] + vec->y * mat.y[0] + vec->z * mat.z[0];
	res.y = vec->x * mat.x[1] + vec->y * mat.y[1] + vec->z * mat.z[1];
	res.z = vec->x * mat.x[2] + vec->y * mat.y[2] + vec->z * mat.z[2];
	return (res);
}

t_vec *rotate_z(t_vec *vec)
{
	t_mat rot;
	float angle;

	angle = 0.01;
	rot.x[0] = cos(angle);
	rot.y[0] = -sin(angle);
	rot.z[0] = 0;
	rot.x[1] = sin(angle);
	rot.y[1] = cos(angle);
	rot.z[1] = 0;
	rot.x[2] = 0;
	rot.y[2] = 0;
	rot.z[2] = 1;

	*vec = mat_mult(vec, rot);
	return (vec);
}