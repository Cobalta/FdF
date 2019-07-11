/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   struct_next.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: brey-gal <brey-gal@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/03 21:10:29 by brey-gal     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/03 21:10:29 by brey-gal    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	vec_next(t_vec **vec, int x, int y, int z, t_map *map)
{
	t_vec	*next_vec;
	t_vec	*new_vec;

	new_vec = *vec;
	while (new_vec->next != NULL)
		new_vec = new_vec->next;
	next_vec = vec_new();
	next_vec->x = x - map->width/2;
	next_vec->y = y - map->height/2;
	next_vec->z = z / 10;
	new_vec->next = next_vec;
}

void	map_line_next(t_map_line **map_line, char *str)
{
	t_map_line	*new_line;
	t_map_line	*next;
	int i;

	i = 1;
	new_line = *map_line;
	while (new_line->next != NULL)
	{
		new_line = new_line->next;
		i++;
	}
	new_line->next = map_line_new();
	next = new_line->next;
	next->nbl = i;
	next->line = ft_strdup(str);
}