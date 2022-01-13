/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbathe <bbathe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 19:05:02 by bbathe            #+#    #+#             */
/*   Updated: 2021/09/17 19:05:07 by bbathe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"
#include "key_macos.h"

int	mouse_hook(int button, int x, int y, t_f *f)
{
	mlx_mouse_get_pos(f->window, &x, &y);
	if (button == MOUSE_SCROLL_UP)
		f->scale = 0.8;
	if (button == MOUSE_SCROLL_DOWN)
		f->scale = 1.25;
	if (button == MOUSE_SCROLL_UP || button == MOUSE_SCROLL_DOWN)
	{
		f->cur->size = f->cur->size * f->scale;
		f->cur->conv_mouse_x = x * f->cur->size * 2 / SIZE - f->cur->size;
		f->cur->conv_mouse_y = f->cur->size - y * f->cur->size * 2 / SIZE;
		draw(f);
	}
	return (0);
}

void	key_hook_color(int key_code, t_f *f)
{
	if (key_code == MAIN_PAD_C)
	{
		f->cur->press_c++;
		if (f->cur->press_c == 1)
			f->cur->color = create_trgb(255, 182, 193);
		if (f->cur->press_c == 2)
			f->cur->color = create_trgb(75, 0, 152);
		if (f->cur->press_c == 3)
			f->cur->color = create_trgb(135, 206, 235);
		if (f->cur->press_c == 4)
		{
			f->cur->color = create_trgb(128, 128, 0);
			f->cur->press_c = 0;
		}
	}
}

int	key_hook(int key_code, t_f *f)
{
	if (key_code == MAIN_PAD_ESC)
		exit(0);
	if (key_code == ARROW_UP)
		f->cur->arrow_y += f->cur->size / SIZE * 100;
	if (key_code == ARROW_DOWN)
		f->cur->arrow_y -= f->cur->size / SIZE * 100;
	if (key_code == ARROW_LEFT)
		f->cur->arrow_x -= f->cur->size / SIZE * 100;
	if (key_code == ARROW_RIGHT)
		f->cur->arrow_x += f->cur->size / SIZE * 100;
	if (f->is_julia && key_code == MAIN_PAD_SPACE)
		f->is_julia_motion = !f->is_julia_motion;
	key_hook_color(key_code, f);
	draw(f);
	return (0);
}
