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
	t_env env;
	t_vec vec;


	if (ac != 2) {
		ft_puterror("usage : ./fdf <map>");
	}
	get_map(av[1], &env.map);
	int i = 0;
	int y;
	while (i < (env.map).height)
	{
		y = 0;
		while (y < (env.map).width)
		{
			//printf("%d ", map.map[i][y]);
			y++;
		}
		//printf("\n");
		i++;
	}
	fdf(&env, &vec);
	map_del(&env.map);
	vec_del(&vec);
	return (0);
}