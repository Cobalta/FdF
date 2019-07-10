/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fill_pixel.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: brey-gal <brey-gal@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/10 03:34:40 by brey-gal     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/10 03:34:40 by brey-gal    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	fill_pixel(char *img_str, int x, int y, t_env *env)
{
	int pos;
	int i;

	i = 0;
	pos = 0;
	while (i < y)
	{
		pos = pos + 4 * env->width;
		i++;
	}
	i = 0;
	while (i < x)
	{
		pos += 4;
		i++;
	}
	img_str[pos] = (char)255;
	img_str[pos + 1] = (char)255;
	img_str[pos + 2] = (char)255;
	img_str[pos + 3] = (char)0;
}
