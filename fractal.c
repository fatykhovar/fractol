/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbathe <bbathe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 14:34:53 by bbathe            #+#    #+#             */
/*   Updated: 2021/10/08 15:28:40 by bbathe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"
#include "key_macos.h"

void	draw(t_f *f)
{
	double	step;

	clean_window(f);
	f->cur->x = 0;
	f->z->x = f->cur->arrow_x - f->cur->size;
	step = 2 * f->cur->size / SIZE;
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
			f->z->y -= step;
		}
		f->cur->x++;
		f->z->x += step;
	}
	mlx_put_image_to_window(f->mlx, f->window, f->img.img, 0, 0);
}

void	fractal_type_julia(int argc, char **argv, t_f *f)
{
	f_init(f);
	f->is_julia = 1;
	f->set_iter = *julia_set_iter;
	if (argc == 2)
		julia(f, 0.36, 0.36);
	else if (argc == 3 && if_number(argv[2]))
		julia(f, double_atoi(argv[2]), 0.36);
	else if (argc == 4 && if_number(argv[2]) && if_number(argv[3]))
		julia(f, double_atoi(argv[2]), double_atoi(argv[3]));
	else
	{
		write(1, "Available parameters: \njulia p q\nmandelbrot\ntricorn\n", 53);
		exit(0);
	}
}

void	fractal_type(int argc, char **argv, t_f *f)
{
	if (argc > 1 && argc < 5 && !ft_strncmp(argv[1], "julia"))
		fractal_type_julia(argc, argv, f);
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
		write(1, "Available parameters: \njulia p q\nmandelbrot\ntricorn\n", 53);
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
