/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fdf.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: brey-gal <brey-gal@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/20 18:44:21 by brey-gal     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/20 18:44:21 by brey-gal    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdio.h>
int		main(int ac, char **av)
{
	t_win win;
	t_map map;

	if (ac != 2) {
		ft_puterror("usage : ./fdf <map>");
	}
	get_map(av[1], &map);
	int i = 0;
	int y;
	while (i < map.lenght)
	{
		y = 0;
		while (y < map.width)
		{
			printf("%d ", map.map[i][y]);
			y++;
		}
		printf("\n");
		i++;
	}
	printf("w %d | L %d\nma", map.width, map.lenght);
	map_del(&map);
	fdf(&win);
	return (0);
}