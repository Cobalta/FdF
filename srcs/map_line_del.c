/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map_line_del.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: brey-gal <brey-gal@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/03 21:26:11 by brey-gal     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/03 21:26:11 by brey-gal    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	map_line_del(t_map_line **map_line)
{
	if ((*map_line)->next != NULL)
		map_line_del((*map_line)->next);
	free((*map_line)->line);
	(*map_line)->nbl = 0;
	free((*map_line));
}