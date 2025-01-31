/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map_to_struct.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: brey-gal <brey-gal@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/04 22:52:45 by brey-gal     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/04 22:52:45 by brey-gal    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	down(t_map *map, t_vec **vec, int x, int y)
{
	t_vec	*down_vec;
	t_vec	*vec_cpy;
	int		i;

	vec_cpy = *vec;
	while (y < map->height - 1)
	{
		x = 0;
		while (x < map->width)
		{
			i = 0;
			vec_cpy = vec_cpy->next;
			down_vec = vec_cpy;
			while (i < map->width)
			{
				if (down_vec->next != NULL)
					down_vec = down_vec->next;
				i++;
			}
			vec_cpy->down = down_vec;
			x++;
		}
		y++;
	}
}

void	right_down(t_map *map, t_vec **vec)
{
	int		x;
	int		y;
	int		i;
	t_vec	*vec_cpy;

	y = 0;
	vec_cpy = *vec;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (vec_cpy->next != NULL)
				vec_cpy = vec_cpy->next;
			vec_cpy->right = vec_cpy->next;
			x++;
		}
		vec_cpy->right = NULL;
		y++;
	}
	down(map, vec, 0, 0);
}

void	map_to_struct(t_map *map, t_vec *vec)
{
	t_vec vec1;

	vec1.y = 0;
	while (vec1.y < map->height)
	{
		vec1.x = 0;
		while (vec1.x < map->width)
		{
			vec_next(&vec, &vec1,
					(float)map->map[(int)vec1.y][(int)vec1.x], map);
			vec1.x++;
		}
		vec1.y++;
	}
	right_down(map, &vec);
}
