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

typedef struct	s_win
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		x;
	int		y;
}				t_win;

#endif
