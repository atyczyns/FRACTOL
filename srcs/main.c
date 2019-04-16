/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyczyns <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 11:17:58 by atyczyns          #+#    #+#             */
/*   Updated: 2019/04/16 13:24:18 by atyczyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	main(int argc, char **argv)
{
	t_all	*glob;
	char	*tab[3];

	tab[1] = "Julia";
	tab[2] = "Mandelbrot";
	if (argc != 2 && argv[1] != tab[1] && argv[1] != tab[2])
	{
		ft_putendl("Usage : ./fractol [name_fractol]");
		ft_putendl("Name of fractol possible : Julia, Mandelbrot");
		return (0);
	}
	if (ft_init_glob(&glob) == EXIT_FAILURE)
		return (0);
	if (fractol(argv[1], &glob) == EXIT_FAILURE)
	{
		ft_putendl("Fractol failed.");
		ft_free_glob(&glob);
		return (0);
	}
	return (0);
	ft_print_map(&glob->map, &(*glob).mlx);
	ctr(glob);
	mlx_loop(glob->mlx->init);
	return (0);
}
