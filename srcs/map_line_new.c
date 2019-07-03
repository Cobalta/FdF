/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map_line_new.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: brey-gal <brey-gal@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/03 21:23:08 by brey-gal     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/03 21:23:08 by brey-gal    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_map_line	*map_line_new(void)
{
	t_map_line	*new_map_line;

	if (!(new_map_line = (t_map_line *)malloc(sizeof(t_map_line))))
		return (NULL);
	new_map_line->line = NULL;
	new_map_line->nbl = 0;
	new_map_line->next = NULL;
	return (new_map_line);
}