/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 20:08:26 by pcarolei          #+#    #+#             */
/*   Updated: 2019/09/25 21:56:59 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include "libft.h"

# define CRD_I (i / map->size)
# define CRD_J ((i % map->size) - tetrimino->offset)
# define USAGE_STR "fillit: wrong number of arguments, should be 1\n"
# define ERROR_STR "error\n"
# define EXIT_WRONG_ARG_COUNT 1
# define EXIT_INVALID_FILE 2

typedef struct	s_map
{
	int		size;
	char	data[0];
}				t_map;

typedef struct	s_tetrimino
{
	char				data[16];
	int					pos;
	int					is_on_map;
	int					offset;
	struct s_tetrimino	*next;
}				t_tetrimino;

int				display_usage(void);
int				display_error(void);
int				map_get_initial_size(t_tetrimino *root);
t_map			*map_create(int size);
void			map_release(t_map *map);
void			map_display(t_map *map);
int				map_count_dots(t_map *map);
int				map_insert(t_map *map, t_tetrimino *tetrimino, int i);
void			map_clean_from_letter(t_map *map, char c);
t_map			*map_fill(t_map *map, t_tetrimino *root);
int				tetrimino_data_validate(char data[16]);
t_tetrimino		*tetrimino_create(int fd, int pos);
t_tetrimino		*tetrimino_create_all(int fd);
void			tetrimino_delete_all(t_tetrimino *root, int err_opt);
t_tetrimino		*tetrimino_get_next_unused(t_tetrimino *cur);
int				tetrimino_get_amount(t_tetrimino *root);
int				tetrimino_put(t_map *map, t_tetrimino *tetrimino);
int				tetrimino_get_amount_unused(t_tetrimino *root);
#endif
