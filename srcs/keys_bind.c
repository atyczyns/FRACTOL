/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_bind.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becaraya <becaraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 16:32:42 by becaraya          #+#    #+#             */
/*   Updated: 2019/04/16 13:21:41 by atyczyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	ft_free_coo_s(t_coo *map)
{
	if ((map->next))
		ft_free_coo_s(map->next);
	if (map)
		free(map);
}

static int	nice_close(t_all *all)
{
	mlx_destroy_image(all->mlx->init, all->mlx->img->ptr);
	free(all->mlx->img);
	mlx_destroy_window(all->mlx->init, all->mlx->win);
	free(all->mlx);
	ft_free_coo_s(all->map->coo);
	free(all->map);
	free(all);
	exit(0);
	return (0);
}

int			ft_init_t_mlx_2___(t_mlx **mlx)
{
	if (!((*mlx)->img->ptr = mlx_new_image((*mlx)->init, WIDTH, HEIGHT)))
	{
		mlx_destroy_window((*mlx)->init, (*mlx)->win);
		free((*mlx)->img);
		free((*mlx)->init);
		free(mlx);
		return (EXIT_FAILURE);
	}
	if (((*mlx)->img->data = mlx_get_data_addr((*mlx)->img->ptr,
			&((*mlx)->img->bpp), &((*mlx)->img->size_l),
				&((*mlx)->img->endian))) == NULL)
	{
		free((*mlx)->img->ptr);
		mlx_destroy_window((*mlx)->init, (*mlx)->win);
		free((*mlx)->img);
		free((*mlx)->init);
		free(mlx);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

static int	command(int key, t_all *glob)
{
	(void)key;
	ft_print_map(&glob->map, &(*glob).mlx);
	return (0);
}

void		ctr(t_all *glob)
{
	mlx_hook(glob->mlx->win, 2, 0, command, glob);
	mlx_hook(glob->mlx->win, 17, 0, nice_close, glob);
}
