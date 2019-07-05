/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   struct_new.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: brey-gal <brey-gal@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/03 21:23:08 by brey-gal     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/03 21:23:08 by brey-gal    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_vec		*vec_new(void)
{
	t_vec	*new_vec;

	if (!(new_vec = (t_vec *)malloc(sizeof(t_vec))))
		return (NULL);
	new_vec->down = NULL;
	new_vec->right = NULL;
	new_vec->next = NULL;
	new_vec->x = 0;
	new_vec->y = 0;
	new_vec->z = 0;
	return (new_vec);
}

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