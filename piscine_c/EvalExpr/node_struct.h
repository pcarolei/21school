/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_struct.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 18:19:56 by pcarolei          #+#    #+#             */
/*   Updated: 2019/02/17 19:02:12 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_STRUCT_H
# define NODE_STRUCT_H

typedef struct	s_node
{
	int				value;
	char			operation;
	struct s_node	*next;
}				t_node;

#endif
