/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyczyns <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 14:08:00 by atyczyns          #+#    #+#             */
/*   Updated: 2019/06/20 13:08:48 by atyczyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void		zoom(int x, int y, t_mlx *mlx)
{
	mlx->x1 = (x / mlx->zoom + mlx->x1) - (x / (mlx->zoom * 1.3));
	mlx->y1 = (y / mlx->zoom + mlx->y1) - (y / (mlx->zoom * 1.3));
	mlx->zoom *= 1.3;
	mlx->iteration_max++;
	mlx->pass = 1;
}

void		de_zoom(int x, int y, t_mlx *mlx)
{
	mlx->x1 = (x / mlx->zoom + mlx->x1) - (x / (mlx->zoom / 1.3));
	mlx->y1 = (y / mlx->zoom + mlx->y1) - (y / (mlx->zoom / 1.3));
	mlx->zoom /= 1.3;
	mlx->iteration_max--;
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
