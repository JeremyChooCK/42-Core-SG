/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechoo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 13:15:10 by jechoo            #+#    #+#             */
/*   Updated: 2023/10/20 13:15:11 by jechoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	handle_key(int key, t_list *data)
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
	drawmandelbrot(data);
	return (0);
}

int	handle_mouse_scroll(int button, int x, int y, t_list *data)
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
	drawmandelbrot(data);
	return (0);
}

int	close_window(t_list *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data);
	exit(1);
	return (0);
}
