/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becaraya <becaraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 09:12:24 by becaraya          #+#    #+#             */
/*   Updated: 2019/05/15 15:24:39 by atyczyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include "../libft/libft.h"
# include <stdio.h>
# include <math.h>
# include <mlx.h>
# include <stdio.h>
# define HEIGHT 500
# define WIDTH 650
# define KEY_ESCAPE 53
# define KEY_PAGE_DOWN 121
# define KEY_PAGE_UP 116

typedef	struct		s_mlx
{
	void			*init;
	void			*win;
	struct s_img	*img;
	int				type;
	float			x1;
	float			x2;
	float			y1;
	float			y2;
	float			c_r;
	float			c_i;
	float			z_r;
	float			z_i;
	float			image_x;
	float			image_y;
	float			tmp;
	int				iteration_max;
	float			color;
	int				pass;
}					t_mlx;

typedef struct		s_img
{
	void			*ptr;
	char			*data;
	int				bpp;
	int				size_l;
	int				endian;
}					t_img;

int					ft_init_mlx(t_mlx **mlx);
int					ft_init_mlx_2(t_mlx **mlx);
void				ft_free_mlx(t_mlx **mlx);
void				ft_put_pixel(t_mlx *mlx, int x, int y, int color);
int					ft_init_t_mlx_2(t_mlx **mlx);
int					fractol(t_mlx **mlx);
void				ctrl(t_mlx **mlx);
void				ft_put_pixel(t_mlx *mlx, int x, int y, int color);
void				do_again(t_mlx **mlx);
void				set_point(t_mlx **mlx);
void				set_point_2(t_mlx **mlx);
void				zoom(t_mlx *mlx);
void				de_zoom(t_mlx *mlx);
int					color(t_mlx *mlx, int i);

#endif
