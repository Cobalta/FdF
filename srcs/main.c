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

int	main(int ac, char **av)
{
	t_env	env;
	t_vec	vec;
	int		i;
	int		y;

	i = 0;
	if (ac != 2)
	{
		ft_puterror("usage : ./fdf <map>");
	}
	get_map(av[1], &env.map);
	while (i < (env.map).height)
	{
		y = 0;
		while (y < (env.map).width)
		{
			y++;
		}
		i++;
	}
	fdf(&env, &vec);
	map_del(&env.map);
	vec_del(&vec);
	return (0);
}
