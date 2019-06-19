/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyczyns <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 11:17:58 by atyczyns          #+#    #+#             */
/*   Updated: 2019/05/22 13:12:04 by atyczyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		do_type(t_mlx *mlx, char *src)
{
	char	*tab[4];

	tab[1] = "Julia";
	tab[2] = "Mandelbrot";
	tab[3] = "Buddhalbrot";
	if (ft_strcmp(src, tab[1]) == 0)
		mlx->type = 1;
	else if (ft_strcmp(src, tab[2]) == 0)
		mlx->type = 2;
	else if (ft_strcmp(src, tab[3]) == 0)
		mlx->type = 3;
	else
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_mlx	*mlx;

	if (ft_init_mlx(&mlx) == EXIT_FAILURE)
		return (0);
	if (argc != 2 || do_type(mlx, argv[1]) != 1)
	{
		ft_free_mlx(&mlx);
		ft_putendl("Usage : ./fractol [name_fractol]");
		ft_putendl("Name of fractol possible : Julia, Mandelbrot");
		return (0);
	}
	if (fractol(&mlx) == EXIT_FAILURE)
	{
		ft_putendl("Fractol failed.");
		ft_free_mlx(&mlx);
		return (0);
	}
	ctrl(&mlx);
	mlx_loop(mlx->init);
	return (0);
}
