/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyczyns <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 11:50:31 by atyczyns          #+#    #+#             */
/*   Updated: 2019/06/20 12:41:09 by atyczyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	do_buddhabrot(t_mlx *mlx)
{
	int		i;
	int		x;
	int		y;

	x = 0;
	while (x++ < mlx->image_x)
	{
		y = 0;
		while (y++ < mlx->image_y)
		{
			i = init_3(&mlx, x, y);
			while (mlx->z_r * mlx->z_r + mlx->z_i * mlx->z_i < 4
				&& ++i < mlx->iteration_max)
			{
				mlx->tmp = mlx->z_r;
				mlx->z_r = mlx->z_r * mlx->z_r - mlx->z_i
				* mlx->z_i + mlx->c_r;
				mlx->z_i = ft_abs(2 * mlx->z_i * mlx->tmp) + mlx->c_i;
			}
			ft_put_pixel(mlx, x, y, color(mlx, i));
		}
	}
}

static void	do_mandelbrot(t_mlx *mlx)
{
	int		i;
	int		y;
	int		x;

	x = 0;
	while (x++ < mlx->image_x)
	{
		y = 0;
		while (y++ < mlx->image_y)
		{
			i = init(&mlx, x, y);
			while (mlx->z_r * mlx->z_r + mlx->z_i * mlx->z_i < 4
				&& ++i < mlx->iteration_max)
			{
				mlx->tmp = mlx->z_r;
				mlx->z_r = mlx->z_r * mlx->z_r - mlx->z_i
				* mlx->z_i + mlx->c_r;
				mlx->z_i = 2 * mlx->z_i * mlx->tmp + mlx->c_i;
			}
			ft_put_pixel(mlx, x, y, color(mlx, i));
		}
	}
}

static void	do_julia(t_mlx *mlx)
{
	int		i;
	int		x;
	int		y;

	x = 0;
	while (x++ < mlx->image_x)
	{
		y = 0;
		while (y++ < mlx->image_y)
		{
			i = init_2(&mlx, x, y);
			while (mlx->z_r * mlx->z_r + mlx->z_i * mlx->z_i < 4
				&& ++i < mlx->iteration_max)
			{
				mlx->tmp = mlx->z_r;
				mlx->z_r = mlx->z_r * mlx->z_r - mlx->z_i
				* mlx->z_i + mlx->c_r;
				mlx->z_i = 2 * mlx->z_i * mlx->tmp + mlx->c_i;
			}
			ft_put_pixel(mlx, x, y, color(mlx, i));
		}
	}
}

int			fractol(t_mlx **mlx)
{
	if ((*mlx)->type == 3)
	{
		if ((*mlx)->pass == 0)
			set_point_3(mlx);
		do_buddhabrot(*mlx);
	}
	if ((*mlx)->type == 2)
	{
		if ((*mlx)->pass == 0)
			set_point(mlx);
		do_mandelbrot((*mlx));
	}
	if ((*mlx)->type == 1)
	{
		if ((*mlx)->pass == 0)
			set_point_2(mlx);
		do_julia(*mlx);
	}
	printf("will put mlx to window\n");
	if (!(*mlx)->img->ptr)
		exit(0);
	mlx_put_image_to_window((*mlx)->init, (*mlx)->win, (*mlx)->img->ptr, 0, 0);
	printf("mlx to window\n");
	return (EXIT_SUCCESS);
}
