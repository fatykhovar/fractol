/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_inits.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbathe <bbathe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 19:06:07 by bbathe            #+#    #+#             */
/*   Updated: 2021/10/07 18:01:53 by bbathe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	cur_init(t_cur *cur)
{
	cur->center_x = SIZE / 2;
	cur->center_y = SIZE / 2;
	cur->k = 0;
	cur->color = create_trgb(0, 0, 128);
	cur->press_c = 0;
	cur->x = 0;
	cur->y = 0;
	cur->mouse_x = -1;
	cur->mouse_y = -1;
	cur->conv_mouse_x = 0;
	cur->conv_mouse_y = 0;
	cur->size = 2;
	cur->arrow_x = 0;
	cur->arrow_y = 0;
}

void	f_init(t_f *f)
{
	f->mlx = mlx_init();
	f->window = mlx_new_window(f->mlx, SIZE, SIZE, "F");
	f->img.img = mlx_new_image(f->mlx, 1080, 1080);
	f->img.addr = mlx_get_data_addr(f->img.img, &f->img.bits_per_pixel,
			&f->img.line_length, &f->img.endian);
	f->scale = 1;
	f->is_julia = 0;
	f->is_julia_motion = 0;
}
