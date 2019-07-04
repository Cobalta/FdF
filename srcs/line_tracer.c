/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   line_tracer.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ebourgeo <ebourgeo@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/27 16:43:00 by ebourgeo     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/27 16:43:00 by ebourgeo    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	linewriter1(t_line *line, t_coor *coor, t_win *win)
{
	int i;
	int px1;
	int py1;

	i = 0;
	px1 = line->px;
	py1 = line->py;

	while (i <= px1)
	{
		mlx_pixel_put(win->mlx_ptr, win->win_ptr, coor->x1, coor->y1, 0xffb5c5);
		i++;
		coor->x1 += line->x_incr;
		line->px -= line->dy;
		if (line->px < 0)
		{
			coor->y1 += line->y_incr;
			line->px += line->dx;
		}
	}
	return ;
}

static void	linewriter2(t_line *line, t_coor *coor, t_win *win)
{
	int i;
	int px1;
	int py1;

	i = 0;
	px1 = line->px;
	py1 = line->py;
	while (i <= py1)
	{
		mlx_pixel_put(win->mlx_ptr, win->win_ptr, coor->x1, coor->y1, 0xffb5c5);
		i++;
		coor->y1 += line->y_incr;
		line->py -= line->dx;
		if (line->py < 0)
		{
			coor->x1 += line->x_incr;
			line->py += line->dy;
		}
	}
	return ;
}

void	line_tracer(t_coor *coor, t_win *win)
{
	t_line line;

	line.px = abs(coor->x2 - coor->x1);
	line.py = abs(coor->y2 - coor->y1);
	line.x_incr = 1;
	line.y_incr = 1;
	if (coor->x1 > coor->x2)
		line.x_incr = -1;
	if (coor->y1 > coor->y2)
		line.y_incr = -1;
	line.dx = 2 * line.px;
	line.dy = 2 * line.py;

	if (line.dx >= line.dy)
		linewriter1(&line, coor, win);
	else if (line.dx < line.dy)
		linewriter2(&line, coor, win);
	return ;
}