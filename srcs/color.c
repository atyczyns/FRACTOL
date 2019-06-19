/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyczyns <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 15:21:33 by atyczyns          #+#    #+#             */
/*   Updated: 2019/06/19 13:27:01 by atyczyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		color(t_mlx *mlx, int i)
{
	if (mlx->type == 2 && mlx->pass == 0)
		mlx->color = 0x0000FF * i * i * mlx->clring / mlx->iteration_max;
	else if (mlx->type == 1 && mlx->pass == 0)
		mlx->color = 0x0000FF * i * i * mlx->clring / mlx->iteration_max;
	else if (mlx->type == 3 && mlx->pass == 0)
		mlx->color = 0xFFFFFF * i * i * mlx->clring / mlx->iteration_max;
	else if (mlx->type == 2)
		mlx->color = 0xFFFFFF * i * i * mlx->clring / mlx->iteration_max;
	return (mlx->color);
}

void	change_color(t_mlx *mlx)
{
	if (mlx->clring == 1)
		mlx->clring = 2;
	else if (mlx->clring == 2)
		mlx->clring = 3;
	else
		mlx->clring = 1;
	printf("mlx->clring = %i\n", mlx->clring);
}
