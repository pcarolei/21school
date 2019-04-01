/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_funcs_part_one_def.h                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 20:10:22 by pcarolei          #+#    #+#             */
/*   Updated: 2019/02/17 20:10:24 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_FUNCS_PART_ONE_DEF_H
# define NODE_FUNCS_PART_ONE_DEF_H

# include "other_funcs.h"

# define MODE1_1 {operand1 = current->value;operation = current->operation;}
# define MODE1_2 {current = current->next;operand2 = current->value;}
# define MODE13 {MODE1_1 MODE1_2}
# define MODE1 {MODE13 res = ft_other_smplcalc(operand1, operand2, operation);}
# define MODE2_1 {operation = current->operation;current = current->next;}
# define MODE2_2 {MODE2_1 operand2 = current->value;}
# define MODE2 {MODE2_2 res = ft_other_smplcalc(res, operand2, operation);}

#endif
