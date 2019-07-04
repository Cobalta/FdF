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

int		*line_convert(char *line, t_map *map)
{
	int		i;
	int		y;
	int		u = 0;
	int		*int_line;
	char	*tmp;

	i = 0;
	y = 0;
	if (!(int_line = (int *)malloc(sizeof(int) * get_nb(line) + 1)))
		return 0;
	map->width = get_nb(line);
	while (i < get_nb(line))
	{
		while (line[u] == ' ')
			u++;
		while ((line[y + u] >= '0' && line[y + u] <= '9') || line[y + u] == '-' || line[y + u] == '+')
			y++;
		tmp = ft_strsub(line, u, y);
		int_line[i] = ft_atoi(tmp);
		free(tmp);
		u = u + y;
		y = 0;
		i++;
	}
	return int_line;
}

void 	map_convert(t_map_line *map_line, t_map *map)
{
	t_map_line	*nb_line;
	int			i;

	nb_line = map_line;
	while (nb_line->next != NULL)
		nb_line = nb_line->next;
	if (!(map->map = (int **)malloc(sizeof(int *) * nb_line->nbl)))
		return ;
	map->lenght = nb_line->nbl;
	i = 0;
	map_line = map_line->next;
	while (map_line->next != NULL)
	{
		map->map[i] = line_convert(map_line->line, map);
		map_line = map_line->next;
		i++;
	}
	map->map[i] = line_convert(map_line->line, map);
}

void	get_map(char *av, t_map *map)
{
	t_map_line	*map_line;
	char		*line;
	int			fd;

	fd = open(av, O_RDONLY);
	map_line = map_line_new();
	while (get_next_line(fd, &line) > 0)
	{
		map_line_next(&map_line, line);
		free(line);
	}
	map_convert(map_line, map);
	map_line_del(map_line);

//	int ton = 0;
//	int pere;
//	while (map[ton][0] != '\0')
//	{
//		pere = 0;
//		while (map[ton][pere])
//		{
//			printf("%d  ", map[ton][pere]);
//			pere++;
//		}
//		ft_putstr("\n");
//		ton++;
//	}
}