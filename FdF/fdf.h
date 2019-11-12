/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 17:11:42 by pcarolei          #+#    #+#             */
/*   Updated: 2019/10/28 14:34:08 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include <math.h>
# include "mlx.h"
# include "libft/libft.h"

# define WIN_SIZE_X 1000
# define WIN_SIZE_Y 1000
# define WIN_TITLE "FdF aka ft_wireframe"
# define C1 0x00FF00
# define C2 0x800080

typedef	struct	s_point
{
	int				x;
	int				y;
	int				z;
	struct s_point	*next;
}				t_point;

typedef	struct	s_vertex
{
	int				x;
	int				y;
	t_point			*point;
	struct s_vertex	*next;
}				t_vertex;

typedef struct	s_edge
{
	t_vertex		*start;
	t_vertex		*end;
	struct s_edge	*next;
}				t_edge;

typedef	struct	s_viewport
{
	int				scale;
	char			mode;
	int				map_width;
	int				map_height;
	int				sh_x;
	int				sh_y;
	int				d_z;
	int				d_x;
	int				d_y;
	double			a_x;
	double			a_y;
	double			a_z;
}				t_viewport;

typedef struct	s_img
{
	void			*img_ptr;
	int				*data;
	int				bpp;
	int				size_line;
	int				endian;
}				t_img;

typedef struct	s_deltas
{
	int				dx;
	int				sx;
	int				dy;
	int				sy;
	int				err;
}				t_deltas;

typedef struct	s_mwr
{
	void			*mlx;
	void			*win;
	t_point			*root_p;
	t_vertex		*root_v;
	t_edge			*root_e;
	t_viewport		*vp;
	t_img			*image;
}				t_mwr;

void			resources_release(t_point *root_p, t_vertex *root_v,
											t_edge *root_e, t_viewport *vp);
void			draw_line(t_img *image, t_edge *e, int color);
void			image_set_pixel(t_img *image, int x, int y, int color);
void			image_clear(t_img *image);
void			image_delete(t_img *image, void *mlx);
t_img			*image_create(void *mlx);
t_point			*point_create(int x, int y, char *z_str);
t_point			*points_get_last(t_point *root_p);
int				map_get_width(char **z_strings);
t_point			*points_delete_width_error(t_point *root_p);
t_point			*points_create(int fd, int *width, int *height);
void			vertex_calc(t_vertex *v, t_viewport *vp);
t_vertex		*vertex_create(t_point *p, t_viewport *vp);
t_vertex		*vertexes_create(t_point *root_p, t_viewport *vp);
t_vertex		*vertex_get_with_offset(t_vertex *v, int offset);
t_edge			*edge_create(t_vertex *v1, t_vertex *v2);
t_edge			*edges_get_last(t_edge *root_e);
t_edge			*edges_create(t_vertex *root_v, int width);
void			edges_recalc(t_edge *root_e, t_viewport *vp);
void			edges_connect(t_img *image, t_edge *root_e);
void			get_centering_shift(t_vertex *root_v, t_viewport *vp);
t_point			*read_line(int y, char **z_strings);
void			z_strings_free(char **z_strings);
void			error_wrong_arg_cnt(void);
t_viewport		*viewport_create(void);
void			center_image(t_vertex *root_v, t_viewport *vp);
void			change_projection_type(t_edge *root_e, t_viewport *vp);
void			redraw(t_mwr *mwr);
void			deal_key_helper(int key, t_mwr *mwr);
int				deal_key(int key, void *param);

#endif
