/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechoo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 15:44:16 by jechoo            #+#    #+#             */
/*   Updated: 2023/10/20 15:47:11 by jechoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include <unistd.h>
# include "../../minilibx-linux/mlx.h"
# include <stdlib.h>
# include <stdio.h>
# define WIDTH 1000
# define HEIGHT 1000
# define MAX_ITERATIONS 200
# define JULIA_RE 0.285
# define JULIA_IM 0.01

typedef struct s_list
{
	double	zoom;
	double	center_real;
	double	center_imag;
	double	center_real2;
	double	center_imag2;
	double	shift_amt;
	double	z_real_squared;
	double	z_imag_new;
	int		color;
	void	*win_ptr;
	void	*mlx_ptr;
	char	*fractal;
}		t_list;

int		ft_strcmp(char *s1, char *s2);
int		handle_key(int key, t_list *data);
int		handle_mouse_scroll(int button, int x, int y, t_list *data);
int		close_window(t_list *data);
void	drawmandelbrot(t_list *data);
void	drawjulia(t_list *data);
void	draw_burning_ship_fractal(t_list *data);
int		handle_key2(int key, t_list *data);
int		handle_mouse_scroll2(int button, int x, int y, t_list *data);
void	colour(t_list *data, int iterations, int x, int y);
int		iterate(int iterations, t_list *data, double *z_real, double *z_imag);
void	declare(t_list *data);

#endif
