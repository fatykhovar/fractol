/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_draw_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbathe <bbathe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 14:46:00 by bbathe            #+#    #+#             */
/*   Updated: 2021/10/08 14:46:16 by bbathe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"
#include "key_macos.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	clean_window(t_f *f)
{
	f->cur->x = 0;
	while (f->cur->x < SIZE)
	{
		f->cur->y = 0;
		while (f->cur->y < SIZE)
		{
			my_mlx_pixel_put(&f->img, f->cur->x, f->cur->y, 0);
			f->cur->y++;
		}
		f->cur->x++;
	}
	mlx_put_image_to_window(f->mlx, f->window, f->img.img, 0, 0);
}
