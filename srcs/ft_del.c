/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_del.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: brey-gal <brey-gal@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/20 18:54:42 by brey-gal     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/20 18:54:42 by brey-gal    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	map_del(t_map *map)
{
	int 	i;

	i = 0;
	while (i < map->lenght)
	{
		free(map->map[i]);
		i++;
	}
	free(map->map);
}

void	map_line_del(t_map_line *map_line)
{
	if (map_line->next != NULL)
		map_line_del(map_line->next);
	free(map_line->line);
	map_line->nbl = 0;
	free(map_line);
}

void	env_del(t_env *env)
{
	env->mlx_ptr = NULL;
	env->win_ptr = NULL;
	env->width = 0;
	env->height = 0;
	env = NULL;
	return ;
}