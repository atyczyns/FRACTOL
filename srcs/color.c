/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyczyns <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 15:21:33 by atyczyns          #+#    #+#             */
/*   Updated: 2019/05/16 14:09:47 by atyczyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		color(t_mlx *mlx, int i)
{
	if (mlx->type == 2 && mlx->pass == 0)
		mlx->color = 0x0000FF * i * i / mlx->iteration_max;
	else if (mlx->type == 1 && mlx->pass == 0)
		mlx->color = 0x0000FF * i * i / mlx->iteration_max;
	else if (mlx->type == 3 && mlx->pass == 0)
		mlx->color = 0x0000FF * i * i / mlx->iteration_max;
	else if (mlx->type == 2)
		mlx->color = 0xFFFFFF * i * i/ mlx->iteration_max;
	return (mlx->color);
}
