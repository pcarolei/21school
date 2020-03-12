/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 16:28:37 by pcarolei          #+#    #+#             */
/*   Updated: 2020/02/20 21:13:03 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODES_H
# define NODES_H
# include "libft/libft.h"

typedef struct	s_node
{
	int				data;
	struct s_node	*next;
}				t_node;

t_node			*node_create(int data);
t_node			*node_find_by_count(t_node *root, int count);
t_node			*node_find_by_data(t_node *root, int data);
int				node_find_max(t_node *root);
int				node_find_min(t_node *root);
int				node_find_med(t_node *root, int elem_count);
int				node_find_max_lesser_than_data(t_node *root, int data);
int				node_find_dist_to_data(t_node *root, int data);
int				node_find_second_min(t_node *root, int min);
int				node_count_nodes_lesser(t_node *root, int data);
void			node_free_list(t_node *root);

#endif
