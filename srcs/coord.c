/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coord.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyczyns <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 14:57:15 by atyczyns          #+#    #+#             */
/*   Updated: 2019/05/16 15:06:39 by atyczyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		ft_init_coord(t_coord **coord)
{
	if (!((*coord) = (t_coord *)malloc(sizeof(t_coord))))
		return (EXIT_FAILURE);
	(*coord)->x = -1;
	(*coord)->y = -1;
	(*coord)->next = NULL;
	return (EXIT_SUCCESS);
}

void	ft_free_coord(t_coord **coord)
{
	if (((*coord)->next))
		ft_free_coord(&(*coord)->next);
	if (*coord)
		free(*coord);
}

int		ft_add_coord(t_coord *tmp_pixel, int x, int y)
{
	t_coord	*new;

	if (!(new = (t_coord *)malloc(sizeof(t_coord))))
		return (EXIT_FAILURE);
	new->next = NULL;
	new->x = x;
	new->y = y;
	tmp_pixel->next = new;
	tmp_pixel = new;
	return (EXIT_SUCCESS);
}
