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

typedef struct	s_win
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		x;
	int		y;
}				t_win;

void	ft_win_del(t_win *win);

#endif