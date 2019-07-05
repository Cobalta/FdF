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

void		env_del(t_env *env);
void		line_tracer(t_seg *seg, t_env *env);
int 		get_next_line(const int fd, char **line);
int			fdf(t_env *env);
void 		get_map(char *av, t_map *map);
t_map_line	*map_line_new(void);
void		map_line_next(t_map_line **map_line, char *str);
void		map_line_del(t_map_line *map_line);
void		map_del(t_map *map);
int			render(t_env *env);
t_vec		project(t_vec *vec);
t_vec		vec_mult(t_vec *vec, int mult);
t_vec		mtx_mult(t_vec *vec, t_mtx mtx);
t_vec		*rotate_x(t_vec *vec);
t_vec		*rotate_y(t_vec *vec);
t_vec		*rotate_z(t_vec *vec);
t_vec 		translate(t_vec *vec, int x, int y, int z);
void		setup(t_env *env);
t_vec		*vec_new(void);
void		vec_next(t_vec **vec, int x, int y ,int z);
void		vec_del(t_vec *vec);
void		map_to_struct(t_map *map, t_vec *vec);

#endif