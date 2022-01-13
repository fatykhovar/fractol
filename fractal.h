/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbathe <bbathe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 19:21:01 by bbathe            #+#    #+#             */
/*   Updated: 2021/10/08 15:07:47 by bbathe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H

# include "mlx/mlx.h"
# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_cur
{
	int		center_x;
	int		center_y;
	double	p;
	double	q;
	int		k;
	int		radius;
	int		color;
	int		press_c;
	int		x;
	int		y;
	int		mouse_x;
	int		mouse_y;
	double	conv_mouse_x;
	double	conv_mouse_y;
	double	size;
	double	arrow_x;
	double	arrow_y;
}	t_cur;

typedef struct s_z
{
	double	x;
	double	y;
}	t_z;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef int	(*t_set_iter)(struct s_cur *cur, struct s_z *z);

typedef struct s_f
{
	double		scale;
	int			is_julia;
	int			is_julia_motion;
	void		*mlx;
	void		*window;
	t_cur		*cur;
	t_z			*z;
	t_data		img;
	t_set_iter	set_iter;
}				t_f;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		ft_strncmp(const char *s1, const char *s2);
void	cur_init(t_cur *cur);
void	f_init(t_f *f);
void	draw(t_f *f);
int		mouse_hook(int button, int x, int y, t_f *f);
void	julia(t_f *f, double p, double q);
int		julia_set_iter(t_cur *cur, t_z *z);
int		julia_motion(int x, int y, t_f *f);
int		mandelbrot_set_iter(t_cur *cur, t_z *z);
void	mandelbrot(t_f *f);
int		tricorn_set_iter(t_cur *cur, t_z *z);
void	tricorn(t_f *f);
int		create_trgb(int r, int g, int b);
int		get_color(t_f *f);
void	key_hook_color(int key_code, t_f *f);
int		key_hook(int key_code, t_f *f);
void	fractal_type(int argc, char **argv, t_f *f);
double	double_atoi(char *str);
void	clean_window(t_f *f);
void	fractal_type_julia(int argc, char **argv, t_f *f);
int		if_number(char *s);

# define SIZE	1080

#endif