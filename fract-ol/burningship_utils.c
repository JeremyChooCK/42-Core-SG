/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechoo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 01:44:41 by jechoo            #+#    #+#             */
/*   Updated: 2023/10/25 01:45:27 by jechoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	handle_key2(int key, t_list *data)
{
	if (key == 4)
		data->zoom *= 1.1;
	else if (key == 5)
		data->zoom /= 1.1;
	else if (key == 65361 || key == 97)
		data->center_real -= data->shift_amt;
	else if (key == 65363 || key == 100)
		data->center_real += data->shift_amt;
	else if (key == 65362 || key == 119)
		data->center_imag -= data->shift_amt;
	else if (key == 65364 || key == 115)
		data->center_imag += data->shift_amt;
	else if (key == 65307 || key == 113)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		mlx_destroy_display(data->mlx_ptr);
		free(data);
		exit(1);
	}
	data->shift_amt = 0.5 / data->zoom;
	draw_burning_ship_fractal(data);
	return (0);
}

int	handle_mouse_scroll2(int button, int x, int y, t_list *data)
{
	double	mouse_real;
	double	mouse_imag;

	mouse_real = ((x - WIDTH / 2.0) * 4.0 / WIDTH)
		/ data->zoom + data->center_real;
	mouse_imag = ((y - HEIGHT / 2.0) * 4.0 / HEIGHT)
		/ data->zoom + data->center_imag;
	if (button == 4)
		data->zoom *= 1.1;
	else if (button == 5)
		data->zoom /= 1.1;
	data->shift_amt = 0.5 / data->zoom;
	data->center_real = mouse_real - ((x - WIDTH / 2.0) * 4.0 / WIDTH)
		/ data->zoom;
	data->center_imag = mouse_imag - ((y - HEIGHT / 2.0) * 4.0 / HEIGHT)
		/ data->zoom;
	draw_burning_ship_fractal(data);
	return (0);
}

void	colour(t_list *data, int iterations, int x, int y)
{
	int	red;
	int	green;
	int	blue;
	int	color;

	red = iterations % 256;
	green = (iterations * 2) % 256;
	blue = (iterations * 3) % 256;
	color = red << 16 | green << 8 | blue;
	mlx_pixel_put(data->mlx_ptr, data->win_ptr,
		x, y, color << 16 | color << 8 | color);
}

int	iterate(int iterations, t_list *data, double *z_real, double *z_imag)
{
	while (iterations < MAX_ITERATIONS)
	{
		data->z_real_squared = *z_real * *z_real - *z_imag * *z_imag;
		data->z_imag_new = 2 * fabs(*z_real * *z_imag)
			+ data->center_imag2;
		*z_real = data->z_real_squared + data->center_real2;
		*z_imag = data->z_imag_new;
		if (*z_real * *z_real + *z_imag * *z_imag > 4)
			break ;
		iterations++;
	}
	return (iterations);
}

void	declare(t_list *data)
{
	if (data->win_ptr == NULL)
		data->win_ptr = mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT, "Fractol");
	mlx_mouse_hook(data->win_ptr, handle_mouse_scroll2, data);
	mlx_key_hook(data->win_ptr, handle_key2, data);
	mlx_hook(data->win_ptr, 17, 0, close_window, data);
}
