/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_point.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyczyns <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 14:03:02 by atyczyns          #+#    #+#             */
/*   Updated: 2019/05/15 15:20:12 by atyczyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"


void	set_point(t_mlx **mlx)
{
	(*mlx)->x1 = -2.1;
	(*mlx)->x2 = 0.6;
	(*mlx)->y1 = -1.2;
	(*mlx)->y2 = 1.2;
	(*mlx)->iteration_max = 50;
	(*mlx)->image_x = 600;
	(*mlx)->image_y = 500;
	(*mlx)->pass = 0;
}

void	set_point_2(t_mlx **mlx)
{
	(*mlx)->x1 = -1;
	(*mlx)->x2 = 1;
	(*mlx)->y1 = -1.2;
	(*mlx)->y2 = 1.2;
	(*mlx)->iteration_max = 150;
	(*mlx)->image_x = 650;
	(*mlx)->image_y = 500;
	(*mlx)->pass = 0;
}

void	zoom(t_mlx *mlx)
{
	float	h;

	h = 0.25;
	mlx->iteration_max = mlx->iteration_max + 10;
	mlx->x1 = mlx->x1 - h;
	mlx->x2 = mlx->x2 + h;
	mlx->y1 = mlx->y1 - h;
	mlx->y2 = mlx->y2 + h;
	mlx->pass++;
}

void	de_zoom(t_mlx *mlx)
{
	float	h;

	h = -0.25;
	mlx->iteration_max = mlx->iteration_max - 10;
	mlx->x1 = mlx->x1 - h;
	mlx->x2 = mlx->x2 + h;
	mlx->y1 = mlx->y1 - h;
	mlx->y2 = mlx->y2 + h;
	mlx->pass++;
}

void	do_again(t_mlx **mlx)
{
	mlx_destroy_window((*mlx)->init, (*mlx)->win);
	if (ft_init_mlx_2(mlx) == EXIT_FAILURE)
	{
		free(&mlx);
		exit(0);
	}
	fractol(mlx);
}
