/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 11:22:37 by pcarolei          #+#    #+#             */
/*   Updated: 2019/11/25 18:55:03 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include "libft/libft.h"
# include "mlx.h"

# define WIN_TITLE "Fractol"
# define WIN_SIZE_X 1024
# define WIN_SIZE_Y 1024
# define WIN_RATIO WIN_SIZE_X / WIN_SIZE_Y
# define ITER_MAX 50

typedef	struct	s_complex
{
	float		re;
	float		im;
}				t_complex;

typedef struct	s_img
{
	void		*img_ptr;
	int			*data;
	int			bpp;
	int			size_line;
	int			endian;
}				t_img;

typedef	struct	s_vp
{
	int			mouse_x;
	int			mouse_y;
	int			iter_max;
	float		offset_x;
	float		offset_y;
	float		scale;
}				t_vp;

typedef struct	s_mwv
{
	void		*mlx;
	void		*win;
	t_vp		*vp;
	t_img		*image;
	t_complex	factor;
	char		*type;
}				t_mwv;

void			image_set_pixel(t_img *image, int x, int y, int color);
void			image_clear(t_img *image);
void			image_delete(t_img *image, void *mlx);
t_img			*image_create(void *mlx);
int				calc_color(int i, int iter_max);
float			complex_abs(t_complex c);
t_complex		complex_create(float re, float im);
void			min_max_create(t_complex *min, t_complex *max,
								float scale, t_mwv *m);
t_complex		c_create(t_complex *factor, int x, int y, t_mwv *m);
void			factor_create(t_complex *factor, float scale, t_mwv *m);
void			z_iter_create(t_complex *z, t_complex *c);
void			burning_ship_z_iter_create(t_complex *z, t_complex *c);
void			mandelbar_z_iter_create(t_complex *z, t_complex *c);
void			celtic_z_iter_create(t_complex *z, t_complex *c);
void			celtic_mandelbar_z_iter_create(t_complex *z, t_complex *c);
void			celtic_perpendicular_z_iter_create(t_complex *z, t_complex *c);
void			perpendicular_mandelbrot_z_iter_create(t_complex *z,
														t_complex *c);
void			perpendicular_bship_z_iter_create(t_complex *z, t_complex *c);
void			perpendicular_buffalo_z_iter_create(t_complex *z, t_complex *c);
void			iter_create(t_complex *z, t_complex *c, char *type);
void			draw_fractal(t_mwv *mwv);
void			julia_wrapper(t_mwv *mwv);
int				fractol_name_check(char *cmd_arg);
void			redraw(t_mwv *mwv);
int				deal_key(int key, void *param);
int				display_usage(void);

#endif
