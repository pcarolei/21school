/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rot42.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 20:22:23 by pcarolei          #+#    #+#             */
/*   Updated: 2019/02/07 20:22:28 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_big_alpha(char c)
{
	int bool;

	bool = (c >= 'A' && c <= 'Z');
	return (bool);
}

int		ft_is_small_alpha(char c)
{
	int bool;

	bool = (c >= 'a' && c <= 'z');
	return (bool);
}

char	get_rot_ascii_big(char c)
{
	int new_c;

	new_c = (((int)c + 16) % 90);
	return (char)new_c;
}

char	get_rot_ascii_small(char c)
{
	char new_c;

	new_c = (((int)c + 16) % 122);
	return (char)new_c;
}

char	*ft_rot42(char *str)
{
	int		i;
	char	test;

	i = 0;
	test = '\0';
	while (str[i])
	{
		if (ft_is_big_alpha(str[i]) == 1)
		{
			test = get_rot_ascii_big(str[i]);
			if (ft_is_big_alpha(test) == 1)
				str[i] = test;
		}
		else if (ft_is_small_alpha(str[i]) == 1)
		{
			test = get_rot_ascii_small(str[i]);
			if (ft_is_small_alpha(test) == 1)
				str[i] = test;
		}
		i++;
	}
	return (str);
}
