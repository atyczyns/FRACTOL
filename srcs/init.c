/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyczyns <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 13:53:00 by atyczyns          #+#    #+#             */
/*   Updated: 2019/06/20 13:33:39 by atyczyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		init_3(t_mlx **mlx, int x, int y)
{
	(*mlx)->zoom_x = (*mlx)->image_x / ((*mlx)->x2 - (*mlx)->x1);
	(*mlx)->zoom_y = (*mlx)->image_y / ((*mlx)->y2 - (*mlx)->y1);
	(*mlx)->pass = 0;
	(*mlx)->c_r = x / (*mlx)->zoom_x + (*mlx)->x1;
	(*mlx)->c_i = y / (*mlx)->zoom_y + (*mlx)->y1;
	(*mlx)->z_r = 0;
	(*mlx)->z_i = 0;
	return (0);
}

int		init_2(t_mlx **mlx, int x, int y)
{
	(*mlx)->x1 += (*mlx)->incr;
	(*mlx)->y1 += (*mlx)->incr;
	(*mlx)->zoom_x = (*mlx)->image_x / ((*mlx)->x2 - (*mlx)->x1);
	(*mlx)->zoom_y = (*mlx)->image_y / ((*mlx)->y2 - (*mlx)->y1);
	(*mlx)->z_r = x / (*mlx)->zoom_x + (*mlx)->x1;
	(*mlx)->z_i = y / (*mlx)->zoom_y + (*mlx)->y1;
	(*mlx)->pass = 0;
	return (0);
}

int		init(t_mlx **mlx, int x, int y)
{
	(*mlx)->zoom_x = (*mlx)->image_x / ((*mlx)->x2 - (*mlx)->x1);
	(*mlx)->zoom_y = (*mlx)->image_y / ((*mlx)->y2 - (*mlx)->y1);
	(*mlx)->pass = 0;
	(*mlx)->c_r = x / (*mlx)->zoom_x + (*mlx)->x1;
	(*mlx)->c_i = y / (*mlx)->zoom_y + (*mlx)->y1;
	(*mlx)->z_r = 0;
	(*mlx)->z_i = 0;
	return (0);
}
