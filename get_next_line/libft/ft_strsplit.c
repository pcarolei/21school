/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 23:56:07 by pcarolei          #+#    #+#             */
/*   Updated: 2019/04/17 18:31:39 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		ft_get_words_cnt(char const *s, char c)
{
	size_t	cnt;
	size_t	i;

	cnt = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			cnt++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
		else
			i++;
	}
	return (cnt);
}

static char			**ft_free_arr(char **arr)
{
	size_t	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
	return (NULL);
}

static char			*ft_create_word(char const *s, char c)
{
	size_t	i;
	char	*new_str;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	new_str = ft_strnew(i);
	if (!new_str)
		return (NULL);
	ft_strncpy(new_str, s, i);
	return (new_str);
}

static const char	*ft_get_next_word_pos(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i] && s[i] != c)
		i++;
	while (s[i] && s[i] == c)
		i++;
	if (!s[i])
		return (NULL);
	return (&s[i]);
}

char				**ft_strsplit(char const *s, char c)
{
	char		**arr;
	const char	*wrd;
	const char	*s_tr;
	size_t		arr_i;

	if (!s)
		return (NULL);
	arr = (char **)malloc(sizeof(char *) * ft_get_words_cnt(s, c) + 1);
	if (!arr)
		return (NULL);
	arr_i = 0;
	s_tr = ft_strtrimc(s, c);
	wrd = s_tr;
	while (arr_i < ft_get_words_cnt(s, c))
	{
		arr[arr_i] = ft_create_word(wrd, c);
		if (!(arr[arr_i]))
			return (ft_free_arr(arr));
		arr_i++;
		wrd = ft_get_next_word_pos(wrd, c);
	}
	free((void *)s_tr);
	arr[arr_i] = NULL;
	return (arr);
}
