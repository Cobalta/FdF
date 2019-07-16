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
	float	z1;
	int		x2;
	int		y2;
	float	z2;
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
	double 	x;
	double  y;
	double 	z;
	int 	z1;
	struct s_vec	*right;
	struct s_vec	*down;
	struct s_vec	*next;
}				t_vec;

typedef	struct	s_mtx
{
	double x[3];
	double y[3];
	double z[3];
}				t_mtx;

typedef struct	s_map
{
	int			**map;
	int			width;
	int			height;
	float		zmax;
}				t_map;

typedef struct	s_img
{
	void	*img_ptr;
	int		width;
	int		height;
}				t_img;

typedef struct	s_env
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		width;
	int		height;
	float	angle_x;
	float	angle_y;
	float	angle_z;
	int		zoom;
	t_map	map;
	t_img	*img;
	void	*img_pptr;
	t_vec	*vec;
	float		R1;
	float		G1;
	float		B1;
	float		R2;
	float		G2;
	float		B2;
	float		R;
	float		G;
	float		B;
	float		alt;
	int			iso;
	float		z1;
	float		z2;
	float		Rres;
	float		Gres;
	float		Bres;
}				t_env;



#endif
