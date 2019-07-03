/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_map.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: brey-gal <brey-gal@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/03 20:19:06 by brey-gal     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/03 20:19:06 by brey-gal    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"


#include <stdio.h>

char 	**map_convert(t_map_line *map_line)
{
	t_map_line	*nb_line;
	char 		**map;
	int			i;

	nb_line = map_line;
	while (nb_line->next != NULL)
		nb_line = nb_line->next;
	if (!(map = (char **)malloc(sizeof(char *) * nb_line->nbl + 1)))
		return (NULL);
	i = 0;
	map_line = map_line->next;
	while (map_line->next != NULL)
	{
		map[i] = ft_strdup(map_line->line);
		map_line = map_line->next;
		i++;
	}
	map[i] = ft_strdup(map_line->line);
	map_line = map_line->next;
	map[i +1] = "\0";
	return (map);
}

char 	**get_map(char *av)
{
	t_map_line	*map_line;
	char		*line;
	char 		**map;
	int			fd;

	fd = open(av, O_RDONLY);
	map_line = map_line_new();
	while (get_next_line(fd, &line) > 0)
	{
		map_line_next(&map_line, line);
		free(line);
	}
	map = map_convert(map_line);
	return (map);
}