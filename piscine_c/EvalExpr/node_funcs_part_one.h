/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_funcs_part_one.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 18:31:31 by pcarolei          #+#    #+#             */
/*   Updated: 2019/02/17 18:31:32 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_FUNCS_PART_ONE_H
# define NODE_FUNCS_PART_ONE_H

t_node	*ft_node_create(int value, char operation);
void	ft_node_push_back(t_node **begin_list, int value, char operation);
int		ft_node_get_chain_length(t_node *begin_list);
void	ft_node_evaluate_chain_high_pr_op_helper(t_node *begin_node);
int		ft_node_evaluate_chain(t_node *begin_list);

#endif
