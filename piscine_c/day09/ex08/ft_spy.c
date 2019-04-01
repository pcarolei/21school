/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 00:24:37 by pcarolei          #+#    #+#             */
/*   Updated: 2019/02/08 00:24:39 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int		ft_strcmp(char *s1, char *s2)
{
	unsigned int i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0')
		i++;
	if (s2[i] == '\0' && s1[i] != '\0')
		return (-1);
	else if (s1[i] == '\0' && s2[i] != '\0')
		return (-1);
	else if ((int)s1[i] != (int)s2[i])
		return (-1);
	return (0);
}

char	*ft_strlowcase(char *str)
{
	unsigned int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		i++;
	}
	return (str);
}

char	*ft_trim_chr(char *str)
{
	int		i;
	int		k;
	char	*trim_str;

	k = 0;
	while (str[i] != '\0')
		i++;
	trim_str = (char*)malloc(sizeof(char) * i + 1);
	i = k;
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			trim_str[k] = str[i];
			k++;
		}
		i++;
	}
	return (str);
}

int		ft_spy(char *str)
{
	char	*str1;
	char	*str2;
	char	*str3;

	str1 = "president";
	str2 = "attack";
	str3 = "bauer";
	str = ft_strlowcase(str);
	str = ft_trim_chr(str);
	if (ft_strcmp(str, str1) == -1 ||
		ft_strcmp(str, str2) == -1 ||
		ft_strcmp(str, str3) == -1)
		return (1);
	else
		return (0);
}

int		main(int argc, char **argv)
{
	int		i;
	char	*str_alert;

	i = 1;
	str_alert = "Alert!!!";
	while (argv[i] != '\0' && (argc > 0))
	{
		if (ft_spy(argv[i]) == 1)
		{
			write(1, "Alert!!!\n", 9);
			return (0);
		}
		i++;
	}
	return (0);
}
