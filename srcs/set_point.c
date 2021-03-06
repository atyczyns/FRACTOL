/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_point.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyczyns <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 14:03:02 by atyczyns          #+#    #+#             */
/*   Updated: 2019/06/20 12:48:54 by atyczyns         ###   ########.fr       */
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
	(*mlx)->incr = 0;
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
	(*mlx)->incr = 0;
	(*mlx)->zoom = 200;
	(*mlx)->c_r = 0.285;
	(*mlx)->c_i = 0.01;
}

void	set_point_3(t_mlx **mlx)
{
	(*mlx)->x1 = -2.2;
	(*mlx)->x2 = 1.1;
	(*mlx)->y1 = -2.5;
	(*mlx)->y2 = 1.25;
	(*mlx)->iteration_max = 50;
	(*mlx)->image_x = 650;
	(*mlx)->image_y = 500;
	(*mlx)->pass = 0;
	(*mlx)->incr = 0;
}
