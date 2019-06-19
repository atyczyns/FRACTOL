/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_bind.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyczyns <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 11:26:10 by atyczyns          #+#    #+#             */
/*   Updated: 2019/06/19 13:46:30 by atyczyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int	nice_close(t_mlx **mlx)
{
	mlx_destroy_image((*mlx)->init, (*mlx)->img->ptr);
	free((*mlx)->img);
	mlx_destroy_window((*mlx)->init, (*mlx)->win);
	printf("essaie de free\n");
	free(*mlx);
	printf("a tout free !\n");
	exit(0);
	return (0);
}

static int	command(int key, t_mlx **mlx)
{
	if (key == KEY_ESCAPE)
		nice_close(mlx);
	if (key == KEY_PAGE_UP)
		zoom(*mlx);
	if (key == KEY_PAGE_DOWN && (*mlx)->iteration_max != 10)
		de_zoom(*mlx);
	if (key == KEY_CHANGE_COLOR)
		change_color((*mlx));
	if (key == KEY_MOVE_JULIA)
		(*mlx)->mouse = !(*mlx)->mouse;
	do_again(mlx);
	return (0);
}

static int	mouse_hook(int mousecode, int x, int y, t_mlx **mlx)
{
	(void)x;
	(void)y;
	if (mousecode == 4)
		zoom(*mlx);
	if (mousecode == 5 && (*mlx)->iteration_max != 10)
		de_zoom(*mlx);
	do_again(mlx);
	return (0);
}

static int	mouse_julia(int x, int y, t_mlx **mlx)
{
	if ((*mlx)->mouse == 1)
	{
		(*mlx)->c_r = x * 2;
		(*mlx)->c_i = y * 2 - 800;
	}
	(*mlx)->pass = 1;
	do_again(mlx);
	return (0);
}

void		ctrl(t_mlx **mlx)
{
	mlx_hook((*mlx)->win, 6, 1 < 6, mouse_julia, mlx);
	mlx_mouse_hook((*mlx)->win, mouse_hook, mlx);
	mlx_hook((*mlx)->win, 2, 0, command, mlx);
	mlx_hook((*mlx)->win, 17, 0, nice_close, mlx);
}
