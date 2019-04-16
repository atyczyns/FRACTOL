/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyczyns <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 11:50:31 by atyczyns          #+#    #+#             */
/*   Updated: 2019/04/16 13:11:11 by atyczyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	do_julia(t_all **glob)
{
	(void)glob;
}

static void	do_mandelbrot(t_all **glob)
{
	(void)glob;
}

int			fractol(char *type, t_all **glob)
{
	char	*tab[3];

	tab[1] = "Julia";
	tab[2] = "Mandelbrot";
	if (type == tab[1])
		do_julia(glob);
	else if (type == tab[2])
		do_mandelbrot(glob);
	return (EXIT_SUCCESS);
}
