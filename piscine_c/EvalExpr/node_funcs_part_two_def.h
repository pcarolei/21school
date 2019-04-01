/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_funcs_part_two_def.h                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 20:38:52 by pcarolei          #+#    #+#             */
/*   Updated: 2019/02/17 20:38:55 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_FUNCS_PART_TWO_DEF_H
# define NODE_FUNCS_PART_TWO_DEF_H

# define I1_1 ft_node_push_back(&root_node, ft_other_atoi(&e_str[i]), 'e')
# define I1_2 return (root_node)
# define I1 {I1_1; I1_2;}
# define NEW_STR ft_string_create_string_from_part(e_str, 1, e_str_len - 1)
# define IBS ft_string_create_string_from_part(e_str, pos_of_op_br + 1, i - 2)
# define POS_NBR ft_string_get_length_of_number(&e_str[i])
# define NC ft_node_create_chain_from_str(IBS, ft_string_get_length(IBS))
# define I3_1 ft_node_push_back(&root_node, ft_other_atoi(&e_str[i]), 'e')
# define I3 {I3_1; return (root_node);}
# define ATOI_ESTR ft_other_atoi(&e_str[POS_NBR]), e_str[pos_of_next_operation]
# define ATOI_ESTR2 ft_other_atoi(&e_str[i]),e_str[pos_of_next_operation]
# define I4_1 ft_node_push_back(&root_node, ATOI_ESTR2)
# define I4 {I4_1; i = pos_of_next_operation + 1;}
# define COND_1 e_str[e_str_len - 1] >= '0' && e_str[e_str_len - 1] <= '9'
# define COND (i >= e_str_len - 1) && COND_1
# define I_N_1 ft_node_push_back(&root_node, ATOI_ESTR)
# define I_N_2 i = pos_of_next_operation + 1
# define I_N {ft_node_push_back(&root_node, ATOI_ESTR); I_N_2;}
# define PONO ft_string_get_number_of_next_operation(NEW_STR, i) + 1
# define F ft_node_push_back(&root_node, ft_node_evaluate_chain(NC), e_str[i])
# define FCK {F, i++;}
# define FLG1 flag += (e_str[i] == '(' && i != pos_of_op_br)
# define FLG2 flag -= (e_str[i] == ')' && flag != 0)
# define FLG {FLG1; FLG2; i++;}
# define DECL1 int 	i
# define DECL2 DECL1; int	pos_of_op_br
# define DECL3 DECL2; int	pos_of_next_operation
# define DECL4 DECL3; int		flag
# define DECL5 DECL4; t_node	*root_node
# define INIT1 i = 0; flag = 0; root_node = ft_node_create(0, '+')
# define SOMEELSE pos_of_op_br = i; flag = 1

# define E0 ft_string_get_number_of_next_operation(e_str, i)
# define E1 pos_of_next_operation = E0
# define E2	ft_node_push_back(&root_node, ATOI_ESTR2)
# define E3 i = pos_of_next_operation + 1
# define E4 {E1; E2; E3;}

# define U1 ft_node_push_back(&root_node, ATOI_ESTR)
# define U2 i = pos_of_next_operation + 1
# define U {U1; U2;}

# define C1 (pos_of_next_operation > e_str_len - 1)
# define C2 ((i >= e_str_len - 1) && e_str[i] >= '0' && e_str[i] <= '9')
# define LASTCOND1 e_str[e_str_len - 1] >= '0'
# define LASTCOND2 e_str[e_str_len - 1] <= '9' && (i >= e_str_len - 1)

#endif
