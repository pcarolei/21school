/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 04:51:32 by pcarolei          #+#    #+#             */
/*   Updated: 2020/02/13 07:57:44 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		check_closing_token(char c)
{
	char	*token_str;
	char	c_str[2];

	token_str = "%cspdiouxXfbrk";
	c_str[0] = c;
	c_str[1] = '\0';
	if (ft_strstr(token_str, c_str))
		return (1);
	return (0);
}

int		get_next_pos(char *fmt_str, int cur_pos)
{
	int	i;

	i = cur_pos;
	if (fmt_str[i] == '%')
	{
		i++;
		while (!check_closing_token(fmt_str[i]) && (fmt_str[i] != '\0'))
			i++;
		if (fmt_str[i] == '\0')
			return (-1);
		return (i + 1);
	}
	while ((fmt_str[i] != '\0') && fmt_str[i] != '%')
		i++;
	return (i);
}

char	*extract_str(char *str, int p1, int p2)
{
	char	*newstr;
	int		i;

	if (!(newstr = (char *)malloc(p2 - p1)))
		return (NULL);
	i = 0;
	while (i < (p2 - p1))
	{
		newstr[i] = str[p1 + i];
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}

t_list	*ft_lstnew_wrapper(char *fmt_str, int pos, int pos_next)
{
	char	*tmp;
	t_list	*tmp_list;

	tmp = extract_str(fmt_str, pos, pos_next);
	tmp_list = ft_lstnew((void *)tmp, ft_strlen(tmp) + 1);
	free(tmp);
	return (tmp_list);
}

t_list	*parser(char *fmt_str)
{
	t_list	*root;
	t_list	*cur;
	int		pos;
	int		pos_next;

	root = ft_lstnew(NULL, 0);
	cur = root;
	pos = 0;
	while (fmt_str[pos])
	{
		if ((pos_next = get_next_pos(fmt_str, pos)) == -1)
			break ;
		cur->next = ft_lstnew_wrapper(fmt_str, pos, pos_next);
		cur = cur->next;
		pos = pos_next;
	}
	return (root);
}
