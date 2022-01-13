/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbathe <bbathe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 19:08:25 by bbathe            #+#    #+#             */
/*   Updated: 2021/10/07 18:02:09 by bbathe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	mandelbrot_set_iter(t_cur *cur, t_z *z)
{
	double	t;
	double	z_x;
	double	z_y;

	cur->k = 0;
	z_x = 0;
	z_y = 0;
	cur->p = z->x;
	cur->q = z->y;
	while (z_x * z_x + z_y * z_y <= 4)
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

void	mandelbrot(t_f *f)
{
	cur_init(f->cur);
	f->cur->p = -2;
	f->cur->q = 2;
	draw(f);
}
