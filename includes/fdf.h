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
# include "/opt/X11/include/X11/X.h"
# include "struct.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <stdio.h>

# define BUFF_SIZE 5000
# define PI 3.1415926535

void		env_del(t_env *env);
void		line_tracer(t_seg *seg, t_env *env);
int			get_next_line(const int fd, char **line);
int			fdf(t_env *env, t_vec *vec);
void		get_map(char *av, t_map *map);
t_map_line	*map_line_new(void);
void		map_line_next(t_map_line **map_line, char *str);
void		map_line_del(t_map_line *map_line);
void		map_del(t_map *map);
int			render(t_vec *vec, t_env *env);
void		project(t_vec *vec);
void		vec_mult(t_vec *vec, int mult);
void		mtx_mult(t_vec *vec, t_mtx mtx);
void		rotate(t_vec *vec, char rot);
void		rotate_x(t_vec *vec, float iter);
void		rotate_y(t_vec *vec, float iter);
void		rotate_z(t_vec *vec, float iter);
void		translate(t_vec *vec, int x, int y, int z);
void		setup(t_env *env);
t_vec		*vec_new(void);
void		vec_next(t_vec **vec, t_vec *vec1, float z, t_map *map);
void		vec_del(t_vec *vec);
void		vec_alt(t_vec *vec1, t_vec *vec2, t_vec *vec3, t_env *env);
void		map_to_struct(t_map *map, t_vec *vec);
void		anglekey(int key, t_env *env);
void		iso(t_vec *vec);
t_vec		vec_cpy(t_vec *vec);
void		fill_pixel(char *img_str, t_seg *seg, t_env *env);
void		get_gradient(t_env *env, int sl, t_seg *seg);
void		display_menu(int key, t_env *env);
void		setup_colors(t_env *env);
void		displaytext(t_env *env);
void		displaytext2(t_env *env);
void		displaytext3(t_env *env);
void		displaytext4(t_env *env);
void		pan(int key, t_env *env);

#endif
