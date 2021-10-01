/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbathe <bbathe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 19:07:17 by bbathe            #+#    #+#             */
/*   Updated: 2021/09/20 16:40:53 by bbathe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	julia_set_iter(t_cur *cur, t_z *z)
{
	double	t;
	double	z_x;
	double	z_y;

	cur->k = 0;
	z_x = z->x;
	z_y = z->y;
	while (z_x * z_x + z_y * z_y <= cur->radius * cur->radius)
	{
		if (cur->k == 200)
			return (1);
		t = z_x;
		z_x = z_x * z_x - z_y * z_y + cur->p;
		z_y = 2 * t * z_y + cur->q;
		cur->k++;
	}
	return (0);
}

int	julia_motion(int x, int y, t_f *f)
{
	if (f->is_julia_motion)
	{
		mlx_mouse_get_pos(f->window, &x, &y);
		f->cur->p = -1 * f->cur->size + x * f->cur->size * 2 / SIZE;
		f->cur->q = f->cur->size - y * f->cur->size * 2 / SIZE;
		draw(f);
	}
	return (0);
}

void	julia(t_f *f)
{
	cur_init(f->cur);
	f->cur->p = 0.36;
	f->cur->q = 0.36;
	draw(f);
}
