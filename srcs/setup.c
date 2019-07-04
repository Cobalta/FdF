/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   setup.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ebourgeo <ebourgeo@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/04 21:32:29 by ebourgeo     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/04 21:32:29 by ebourgeo    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

void	setup(t_draw *draw)
{
	t_vec vec1;
	t_vec vec2;
	t_vec vec3;
	t_vec vec4;

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
	return;
}