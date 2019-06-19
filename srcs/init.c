/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyczyns <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 13:53:00 by atyczyns          #+#    #+#             */
/*   Updated: 2019/06/19 13:23:52 by atyczyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		init_3(t_mlx **mlx, int x, int y)
{
	float	zoom_x;
	float	zoom_y;

	zoom_x = (*mlx)->image_x / ((*mlx)->x2 - (*mlx)->x1);
	zoom_y = (*mlx)->image_y / ((*mlx)->y2 - (*mlx)->y1);
	(*mlx)->c_r = x / zoom_x + (*mlx)->x1;
	(*mlx)->c_i = y / zoom_y + (*mlx)->y1;
	(*mlx)->z_r = 0;
	(*mlx)->z_i = 0;
	return (0);
}

int		init_2(t_mlx **mlx, int x, int y)
{
	float	zoom_x;
	float	zoom_y;

	(*mlx)->x1 = (*mlx)->x1 + (*mlx)->incr;
	(*mlx)->y1 = (*mlx)->y1 + (*mlx)->incr;
	(*mlx)->pass = 0;
	zoom_x = (*mlx)->image_x / ((*mlx)->x2 - (*mlx)->x1);
	zoom_y = (*mlx)->image_y / ((*mlx)->y2 - (*mlx)->y1);
	(*mlx)->c_r = 0.280;
	(*mlx)->c_i = 0.01;
	(*mlx)->z_r = x / zoom_x + (*mlx)->x1;
	(*mlx)->z_i = y / zoom_y + (*mlx)->y1;
	return (0);
}

int		init(t_mlx **mlx, int x, int y)
{
	float	zoom_x;
	float	zoom_y;

	zoom_x = (*mlx)->image_x / ((*mlx)->x2 - (*mlx)->x1);
	zoom_y = (*mlx)->image_y / ((*mlx)->y2 - (*mlx)->y1);
	(*mlx)->c_r = x / zoom_x + (*mlx)->x1;
	(*mlx)->c_i = y / zoom_y + (*mlx)->y1;
	(*mlx)->z_r = 0;
	(*mlx)->z_i = 0;
	return (0);
}
