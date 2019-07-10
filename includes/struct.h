/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   struct.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: brey-gal <brey-gal@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/27 16:50:44 by brey-gal     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/27 16:50:44 by brey-gal    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FDF_STRUCT_H
# define FDF_STRUCT_H


typedef struct	s_line
{
	int		px;
	int		py;
	int		dx;
	int		dy;
	int		x_incr;
	int		y_incr;

}				t_line;

typedef struct	s_seg
{
	int		x1;
	int		y1;
	int		x2;
	int		y2;
	void	*next;
}				t_seg;

typedef	struct	s_map_line
{
	char 	*line;
	int		nbl;
	void	*next;
}				t_map_line;

typedef	struct	s_vec
{
	float 	x;
	float 	y;
	float 	z;
	void	*right;
	void	*down;
	void	*next;
}				t_vec;

typedef	struct	s_mtx
{
	float x[3];
	float y[3];
	float z[3];
}				t_mtx;

typedef struct	s_map
{
	int		**map;
	int		width;
	int		height;
}				t_map;

typedef struct	s_env
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_map	map;
	int		width;
	int		height;
	t_vec vec1;
	t_vec vec2;
	t_vec vec3;
	t_vec vec4;
	t_vec vec5;
	t_vec vec6;
	t_vec vec7;
	t_vec vec8;
	t_vec *vec;
}				t_env;

typedef struct	s_img
{
	void	*img_ptr;
	int		width;
	int		height;
}				t_img;

#endif
