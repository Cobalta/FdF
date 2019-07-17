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

static void	linewriter1(t_line *line, t_seg *seg, t_env *env)
{
	int i;
	int px1;
	int py1;
	int bpp;
	int sl;
	int endian;
	char *img_str;

	i = 0;
	px1 = line->px;
	py1 = line->py;
	img_str = mlx_get_data_addr(env->img_pptr, &(bpp), &(sl), &(endian));
	setup_colors(env);
	get_gradient(env, px1, seg);
	while (i <= px1)
	{
		fill_pixel(img_str, seg, env);
		i++;
		seg->x1 += line->x_incr;
		line->px -= line->dy;
		if (line->px < 0)
		{
			seg->y1 += line->y_incr;
			line->px += line->dx;
		}
	}
}

static void	linewriter2(t_line *line, t_seg *seg, t_env *env)
{
	int i;
	int px1;
	int py1;
	int bpp;
	int sl;
	int endian;
	char *img_str;

	i = 0;
	px1 = line->px;
	py1 = line->py;

	img_str = mlx_get_data_addr(env->img_pptr, &(bpp), &(sl), &(endian));
	setup_colors(env);
	get_gradient(env, py1, seg);
	while (i <= py1)
	{
		fill_pixel(img_str, seg, env);
		i++;
		seg->y1 += line->y_incr;
		line->py -= line->dx;
		if (line->py < 0)
		{
			seg->x1 += line->x_incr;
			line->py += line->dy;
		}
	}
	return ;
}

void	line_tracer(t_seg *seg, t_env *env)
{
	t_line line;

	line.px = abs(seg->x2 - seg->x1);
	line.py = abs(seg->y2 - seg->y1);
	line.x_incr = 1;
	line.y_incr = 1;
	if (seg->x1 > seg->x2)
		line.x_incr = -1;
	if (seg->y1 > seg->y2)
		line.y_incr = -1;
	line.dx = 2 * line.px;
	line.dy = 2 * line.py;
	if (line.dx >= line.dy)
		linewriter1(&line, seg, env);
	else if (line.dx < line.dy)
		linewriter2(&line, seg, env);
	return ;
}