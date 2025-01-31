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

int		get_nb(char *line)
{
	int i;
	int nb;
	int space;

	i = 0;
	nb = 0;
	space = 0;
	while (line[i])
	{
		if (line[i] != ' ' && space == 0)
		{
			nb++;
			space = 1;
		}
		if (line[i] == ' ' && space == 1)
			space = 0;
		i++;
	}
	return (nb);
}

int		*line_convert(char *line, t_map *map, char *tmp)
{
	int		i[3];
	int		*int_line;

	i[0] = 0;
	i[1] = 0;
	i[2] = 0;
	if (!(int_line = (int *)malloc(sizeof(int) * get_nb(line) + 1)))
		return (0);
	while (i[0] < get_nb(line))
	{
		while (line[i[2]] == ' ')
			i[2]++;
		while (line[i[1] + i[2]] != ' ' && line[i[1] + i[2]] != '\0')
			i[1]++;
		tmp = ft_strsub(line, i[2], i[1]);
		int_line[i[0]] = ft_atoi(tmp);
		if (int_line[i[0]] > map->zmax)
			map->zmax = int_line[i[0]];
		if (int_line[i[0]] < map->zmin)
			map->zmin = int_line[i[0]];
		free(tmp);
		operation(i);
	}
	return (int_line);
}

void	map_convert(t_map_line *map_line, t_map *map)
{
	t_map_line	*nb_line;
	int			i;

	nb_line = map_line;
	while (nb_line->next != NULL)
		nb_line = nb_line->next;
	if (!(map->map = (int **)malloc(sizeof(int *) * nb_line->nbl)))
		return ;
	map->height = nb_line->nbl;
	i = 0;
	map_line = map_line->next;
	while (map_line->next != NULL)
	{
		map->map[i] = line_convert(map_line->line, map, NULL);
		map_line = map_line->next;
		i++;
	}
	map->width = get_nb(map_line->line);
	map->map[i] = line_convert(map_line->line, map, NULL);
}

int		check_linelen(t_map_line *map_line)
{
	int line_len;

	line_len = get_nb(map_line->line);
	while (map_line->next != NULL)
	{
		if ((get_nb(map_line->line)) != line_len)
			return (0);
		map_line = map_line->next;
	}
	if ((get_nb(map_line->line)) != line_len)
		return (0);
	return (1);
}

void	get_map(char *av, t_map *map)
{
	t_map_line	*map_line;
	char		*line;
	int			fd;

	map->zmax = 0;
	if ((fd = open(av, O_RDONLY)) < 0)
		ft_puterror("Invalid map\nusage : ./fdf <valid map>");
	map_line = map_line_new();
	while (get_next_line(fd, &line) > 0)
	{
		map_line_next(&map_line, line);
		free(line);
	}
	if ((check_linelen(map_line->next)) == 0)
		ft_puterror("Found wrong line length. Exiting.");
	map_convert(map_line, map);
	map_line_del(map_line);
}
