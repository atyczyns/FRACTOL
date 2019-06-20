/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becaraya <becaraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 09:12:24 by becaraya          #+#    #+#             */
/*   Updated: 2019/06/20 12:41:17 by atyczyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include "../libft/libft.h"
# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <mlx.h>
# define HEIGHT 500
# define WIDTH 650
# define KEY_ESCAPE 53
# define KEY_PAGE_DOWN 121
# define KEY_PAGE_UP 116
# define KEY_CHANGE_COLOR 49
# define KEY_MOVE_JULIA 119

typedef	struct		s_mlx
{
	struct s_img	*img;
	void			*init;
	void			*win;
	int				mouse;
	int				type;
	int				iteration_max;
	int			clring;
	int				pass;
	int				**tab;
	int				incr;
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
	float			zoom_x;
	float			zoom_y;
	float			zoom;
	float		color;
}					t_mlx;

typedef struct		s_coord
{
	int				x;
	int				y;
	struct s_coord	*next;
}					t_coord;

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
int					ft_init_t_mlx_2(t_mlx **mlx);
int					fractol(t_mlx **mlx);
int					color(t_mlx *mlx, int i);
int					init(t_mlx **mlx, int x, int y);
int					init_2(t_mlx **mlx, int x, int y);
int					init_3(t_mlx **mlx, int x, int y);
int					ft_init_coord(t_coord **coord);
int					ft_add_coord(t_coord *tmp_pixel, int x, int y);
int					ft_abs(int value);
int					do_type(t_mlx *mlx, char *src);
void				ft_free_mlx(t_mlx **mlx);
void				ft_put_pixel(t_mlx *mlx, int x, int y, int color);
void				ctrl(t_mlx **mlx);
void				ft_put_pixel(t_mlx *mlx, int x, int y, int color);
void				do_again(t_mlx **mlx);
void				set_point(t_mlx **mlx);
void				set_point_2(t_mlx **mlx);
void				set_point_3(t_mlx **mlx);
void				zoom(int x, int y, t_mlx *mlx);
void				de_zoom(int x, int y, t_mlx *mlx);
void				ft_free_coord(t_coord **coord);
void				change_color(t_mlx *mlx);

#endif
