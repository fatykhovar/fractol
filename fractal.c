/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbathe <bbathe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 18:20:33 by bbathe            #+#    #+#             */
/*   Updated: 2021/09/20 16:45:34 by bbathe           ###   ########.fr       */
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

void	draw(t_f *f)
{
	f->cur->x = 0;
	f->z->x = f->cur->arrow_x - f->cur->size;
	while (f->cur->x < SIZE)
	{
		f->cur->y = 0;
		f->z->y = f->cur->arrow_y + f->cur->size;
		while (f->cur->y < SIZE)
		{
			f->set_iter(f->cur, f->z);
			if (f->cur->k == 200)
				my_mlx_pixel_put(&f->img, f->cur->x, f->cur->y, 0);
			else
				my_mlx_pixel_put(&f->img, f->cur->x, f->cur->y, get_color(f));
			f->cur->y++;
			f->z->y -= 2 * f->cur->size / SIZE;
		}
		f->cur->x++;
		f->z->x += 2 * f->cur->size / SIZE;
	}
	mlx_put_image_to_window(f->mlx, f->window, f->img.img, 0, 0);
}

void	fractal_type(int argc, char **argv, t_f *f)
{
	if (argc == 2 && !ft_strncmp(argv[1], "julia"))
	{
		f_init(f);
		f->is_julia = 1;
		f->set_iter = *julia_set_iter;
		julia(f);
	}
	else if (argc == 2 && !ft_strncmp(argv[1], "mandelbrot"))
	{
		f_init(f);
		f->set_iter = *mandelbrot_set_iter;
		mandelbrot(f);
	}
	else if (argc == 2 && !ft_strncmp(argv[1], "tricorn"))
	{
		f_init(f);
		f->set_iter = *tricorn_set_iter;
		tricorn(f);
	}
	else
	{
		write(1, "Available parameters: \njulia\nmandelbrot\ntricorn\n", 49);
		exit(0);
	}
}

int	main(int argc, char **argv)
{
	t_f		*f;
	t_cur	*cur;
	t_z		*z;

	f = malloc(sizeof(t_f));
	cur = malloc(sizeof(t_cur));
	z = malloc(sizeof(t_z));
	f->cur = cur;
	f->z = z;
	fractal_type(argc, argv, f);
	mlx_hook(f->window, 2, 1L << 0, key_hook, f);
	mlx_mouse_hook(f->window, mouse_hook, f);
	if (f->is_julia)
		mlx_hook(f->window, 6, 0, julia_motion, f);
	mlx_loop(f->mlx);
	return (0);
}
