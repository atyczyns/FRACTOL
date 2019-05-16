/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyczyns <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 14:08:00 by atyczyns          #+#    #+#             */
/*   Updated: 2019/05/16 14:08:57 by atyczyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

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
