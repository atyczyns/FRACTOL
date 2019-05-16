/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_bind.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyczyns <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 11:26:10 by atyczyns          #+#    #+#             */
/*   Updated: 2019/05/15 14:24:11 by atyczyns         ###   ########.fr       */
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
	if (key == KEY_PAGE_DOWN)
		de_zoom(*mlx);
	do_again(mlx);
	return (0);
}

void		ctrl(t_mlx **mlx)
{
	mlx_hook((*mlx)->win, 2, 0, command, mlx);
	mlx_hook((*mlx)->win, 17, 0, nice_close, mlx);
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
