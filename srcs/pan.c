/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   pan.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ebourgeo <ebourgeo@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/18 16:13:07 by ebourgeo     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/18 16:13:07 by ebourgeo    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	pan(int key, t_env *env)
{
	if (key == 86)
		env->pan_x -= 30;
	if (key == 88)
		env->pan_x += 30;
	if (key == 84)
		env->pan_y += 30;
	if (key == 91)
		env->pan_y -= 30;
}
