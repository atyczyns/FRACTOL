/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyczyns <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 14:08:00 by atyczyns          #+#    #+#             */
/*   Updated: 2019/06/19 13:18:14 by atyczyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void		zoom(t_mlx *mlx)
{
	float	h;

	h = 0.25;
	mlx->iteration_max = mlx->iteration_max + 10;
	mlx->x1 = mlx->x1 - h;
	mlx->x2 = mlx->x2 + h;
	mlx->y1 = mlx->y1 - h;
	mlx->y2 = mlx->y2 + h;
	mlx->pass = 1;
}

void		de_zoom(t_mlx *mlx)
{
	float	h;

	h = -0.25;
	mlx->iteration_max = mlx->iteration_max - 10;
	mlx->x1 = mlx->x1 - h;
	mlx->x2 = mlx->x2 + h;
	mlx->y1 = mlx->y1 - h;
	mlx->y2 = mlx->y2 + h;
	mlx->pass = 1;
}

void		do_again(t_mlx **mlx)
{
	mlx_destroy_image((*mlx)->init, (*mlx)->img->ptr);
	if (ft_init_mlx_2(mlx) == EXIT_FAILURE)
	{
		free(&mlx);
		exit(0);
	}
	fractol(mlx);
}

int			ft_abs(int value)
{
	if (value < 0)
		value = -value;
	return (value);
}

void	ft_put_pixel(t_mlx *mlx, int x, int y, int color)
{
	int		i;

	if (x < WIDTH && x >= 0 && y < HEIGHT && y >= 0)
	{
		i = (x * mlx->img->bpp / 8) + (y * mlx->img->size_l);
		mlx->img->data[i] = color;
		mlx->img->data[++i] = color >> 8;
		mlx->img->data[++i] = color >> 16;
	}
}
