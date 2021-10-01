/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tricorn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbathe <bbathe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 19:08:30 by bbathe            #+#    #+#             */
/*   Updated: 2021/09/20 16:40:24 by bbathe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	tricorn_set_iter(t_cur *cur, t_z *z)
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
		t = z_x * z_x - z_y * z_y + z->x;
		z_y = -2 * z_x * z_y + z->y;
		z_x = t;
		cur->k++;
	}
	return (0);
}

void	tricorn(t_f *f)
{
	cur_init(f->cur);
	f->cur->p = 0.36;
	f->cur->q = 0.36;
	draw(f);
}
