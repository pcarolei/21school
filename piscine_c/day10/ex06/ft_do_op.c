/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do-op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 15:42:45 by pcarolei          #+#    #+#             */
/*   Updated: 2019/02/11 15:42:47 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_op_funcs.h"
#include "ft_other_funcs.h"

int		ft_detect_op(int n1, int n2, char *op, int (*fun_tab[5])(int, int))
{
	int	i;

	i = 0;
	while (fun_tab[i++] && i != 5)
	{
		if (op[0] == '+')
			return (ft_op_plus(n1, n2));
		else if (op[0] == '-')
			return (ft_op_minus(n1, n2));
		else if (op[0] == '*')
			return (ft_op_mult(n1, n2));
		else if (op[0] == '/')
			return (ft_op_div(n1, n2));
		else if (op[0] == '%')
			return (ft_op_mod(n1, n2));
		i++;
	}
	return (0);
}

int		ft_do_op(char *str_n1, char *op, char *str_n2)
{
	int	n1;
	int	n2;
	int (*fun_tab[5])(int, int);

	n1 = ft_atoi(str_n1);
	n2 = ft_atoi(str_n2);
	fun_tab[0] = &ft_op_plus;
	fun_tab[1] = &ft_op_minus;
	fun_tab[2] = &ft_op_mult;
	fun_tab[3] = &ft_op_div;
	fun_tab[4] = &ft_op_mod;
	return (ft_detect_op(n1, n2, op, fun_tab));
}

int		main(int argc, char **argv)
{
	int		res;
	char	op;

	res = 0;
	op = argv[2][0];
	if (argc != 4)
		return (0);
	else if (argv[2][1] != '\0')
	{
		ft_putnbr(res);
		ft_putchar('\n');
		return (0);
	}
	else
	{
		if (op == '/' && argv[3][1] == '\0' && argv[3][0] - '0' == 0)
			write(1, "Stop : division by zero", 23);
		else if (op == '%' && argv[3][1] == '\0' && argv[3][0] - '0' == 0)
			write(1, "Stop : modulo by zero", 21);
		else
			ft_putnbr(ft_do_op(argv[1], argv[2], argv[3]));
		ft_putchar('\n');
	}
	return (0);
}
