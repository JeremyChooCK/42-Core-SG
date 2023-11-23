/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechoo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 15:07:48 by jechoo            #+#    #+#             */
/*   Updated: 2023/10/20 15:07:49 by jechoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	mandelbrot(double real, double imag)
{
	double	z_real;
	double	z_imag;
	int		n;
	double	z_real_squared;
	double	z_imag_new;

	z_real = real;
	z_imag = imag;
	n = 0;
	while (++n < MAX_ITERATIONS)
	{
		z_real_squared = z_real * z_real - z_imag * z_imag;
		z_imag_new = 2 * z_real * z_imag + imag;
		z_real = z_real_squared + real;
		z_imag = z_imag_new;
		if (z_real * z_real + z_imag * z_imag > 4)
			return (n);
	}
	return (MAX_ITERATIONS);
}

static int	julia(double real, double imag)
{
	double	z_real;
	double	z_imag;
	int		n;
	double	z_real_squared;
	double	z_imag_new;

	z_real = real;
	z_imag = imag;
	n = 0;
	while (++n < MAX_ITERATIONS)
	{
		z_real_squared = z_real * z_real - z_imag * z_imag;
		z_imag_new = 2 * z_real * z_imag + JULIA_IM;
		z_real = z_real_squared + JULIA_RE;
		z_imag = z_imag_new;
		if (z_real * z_real + z_imag * z_imag > 4)
			return (n);
	}
	return (MAX_ITERATIONS);
}

static void	plot_util(t_list *data, int x, int y, int value)
{
	if (value > 0 && value <= ((MAX_ITERATIONS / 2) / 3))
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, 0xFFFFFF);
	else if (value > ((MAX_ITERATIONS / 2) / 3)
		&& value <= ((MAX_ITERATIONS / 2) / 3) * 2)
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, 0x016345);
	else if (value > ((MAX_ITERATIONS / 2) / 3) * 2
		&& value < (MAX_ITERATIONS / 2))
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, 0xF6FF00);
	else
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, 0x026648);
}

static void	plot(t_list *data, int y)
{
	int		x;
	double	real;
	double	imag;
	int		value;

	x = 0;
	while (++x < WIDTH)
	{
		real = ((x - WIDTH / 2.0) * 4.0 / WIDTH)
			/ data->zoom + data->center_real;
		imag = ((y - HEIGHT / 2.0) * 4.0 / HEIGHT)
			/ data->zoom + data->center_imag;
		if (ft_strcmp(data->fractal, "mandelbrot") == 0)
			value = mandelbrot(real, imag);
		else if (ft_strcmp(data->fractal, "julia") == 0)
			value = julia(real, imag);
		if (value == MAX_ITERATIONS)
			mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, 0x000000);
		if (value > 0 && value <= MAX_ITERATIONS / 2)
			plot_util(data, x, y, value);
		if (value > MAX_ITERATIONS / 2 && value < MAX_ITERATIONS)
			mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, 0x00FFB3);
	}
}

void	drawmandelbrot(t_list *data)
{
	int	y;

	if (data->win_ptr == NULL)
		data->win_ptr = mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT, "Fractol");
	mlx_mouse_hook(data->win_ptr, handle_mouse_scroll, data);
	mlx_key_hook(data->win_ptr, handle_key, data);
	mlx_hook(data->win_ptr, 17, 0, close_window, data);
	y = 0;
	while (++y < HEIGHT)
		plot(data, y);
}
