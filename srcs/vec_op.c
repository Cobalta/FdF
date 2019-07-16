/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   vec_op.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ebourgeo <ebourgeo@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/12 08:57:56 by ebourgeo     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/12 08:57:56 by ebourgeo    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	vec_mult(t_vec *vec, int mult)
{
	vec->x *= mult;
	vec->y *= mult;
	vec->z *= mult;
}

void	translate(t_vec *vec, int x, int y, int z)
{
	vec->x += x;
	vec->y += y;
	vec->z += z;
}

void	iso(t_vec *vec)
{
	int previous_x;
	int previous_y;

	previous_x = vec->x;
	previous_y = vec->y;
	vec->x = (previous_x - previous_y) * cos(0.523599);
	vec->y = -vec->z + (previous_x + previous_y) * sin(0.523599);
}

t_vec	vec_cpy(t_vec *vec)
{
	t_vec cpy;

	cpy.x = vec->x;
	cpy.y = vec->y;
	cpy.z = vec->z;
	return (cpy);
}