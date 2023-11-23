/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechoo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 16:06:52 by jechoo            #+#    #+#             */
/*   Updated: 2023/10/24 16:07:14 by jechoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	possibleinputs(void)
{
	write(1, "mandelbrot julia burningship\n", 29);
}

int	main(int ac, char **av)
{
	t_list	*data;

	data = malloc(sizeof(t_list));
	data->zoom = 1.0;
	data->shift_amt = 0.1;
	data->win_ptr = NULL;
	data->mlx_ptr = mlx_init();
	if (ac == 2 && (ft_strcmp(av[1], "mandelbrot") == 0
			|| ft_strcmp(av[1], "julia") == 0))
	{
		data->fractal = av[1];
		drawmandelbrot(data);
	}
	else if (ac == 2 && (ft_strcmp(av[1], "burningship") == 0))
		draw_burning_ship_fractal(data);
	else
		possibleinputs();
	mlx_loop(data->mlx_ptr);
	if (data->win_ptr)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	if (data->mlx_ptr)
		mlx_destroy_display(data->mlx_ptr);
	free(data);
	return (0);
}
