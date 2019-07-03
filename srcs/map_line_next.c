/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map_line_next.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: brey-gal <brey-gal@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/03 21:10:29 by brey-gal     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/03 21:10:29 by brey-gal    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

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