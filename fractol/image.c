/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 07:52:46 by pcarolei          #+#    #+#             */
/*   Updated: 2019/11/12 12:16:16 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	image_set_pixel(t_img *image, int x, int y, int color)
{
	if (x < 0 || y < 0 || x >= WIN_SIZE_X || y >= WIN_SIZE_Y)
		return ;
	image->data[x + y * WIN_SIZE_Y] = color;
}

void	image_clear(t_img *image)
{
	ft_bzero(image->data, WIN_SIZE_X * WIN_SIZE_Y * image->bpp / 8);
}

void	image_delete(t_img *image, void *mlx)
{
	if (image)
	{
		if (image->img_ptr)
			mlx_destroy_image(mlx, image->img_ptr);
		ft_memdel((void **)&image);
	}
}

t_img	*image_create(void *mlx)
{
	t_img	*image;

	image = (t_img *)malloc(sizeof(t_img));
	if (!image)
		return (NULL);
	if (!(image->img_ptr = mlx_new_image(mlx, WIN_SIZE_X, WIN_SIZE_Y)))
	{
		image_delete(image, mlx);
		return (NULL);
	}
	image->data = (int *)mlx_get_data_addr(image->img_ptr, &image->bpp,
											&image->size_line, &image->endian);
	return (image);
}
