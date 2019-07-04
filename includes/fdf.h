/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fdf.h                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: brey-gal <brey-gal@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/20 18:44:15 by brey-gal     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/20 18:44:15 by brey-gal    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FDF_FDF_H
# define FDF_FDF_H

# include "../libft/libft.h"
# include "../minilibx/mlx.h"
# include "struct.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <stdio.h>

# define BUFF_SIZE 5000

void		win_del(t_win *win);
void		line_tracer(t_seg *seg, t_win *win);
int 		get_next_line(const int fd, char **line);
int			fdf(t_win *win);
void 		get_map(char *av, t_map *map);
t_map_line	*map_line_new(void);
void		map_line_next(t_map_line **map_line, char *str);
void		map_line_del(t_map_line *map_line);
void		map_del(t_map *map);
int			render(t_win *win);
t_vec		mat_mult(t_vec *vec, t_mat mat);
t_vec		*rotate_z(t_vec *vec);
void		setup(t_draw *draw);

#endif