/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarolei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 23:56:07 by pcarolei          #+#    #+#             */
/*   Updated: 2019/04/16 03:32:29 by pcarolei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		ft_get_words_cnt(char const *s, char c)
{
	size_t	cnt;
	size_t	s_len;
	size_t	i;

	cnt = 0;
	s_len = ft_strlen(s);
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

static const char	*ft_get_next_word_pos(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			while (s[i] == c)
				i++;
		}
		else
		{
			while (s[i] != c)
			{
				if (s[i] == '\0')
					return (NULL);
				i++;
			}
			while (s[i] == c)
				i++;
			return (&s[i]);
		}
	}
	return (NULL);
}

static char			*ft_create_word(char const *s, char c)
{
	size_t	i;
	char	*new_str;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	new_str = ft_strnew(i);
	ft_strncpy(new_str, s, i);
	return (new_str);
}

static char			*ft_strtrimc(char const *s, char c)
{
	size_t	start;
	size_t	end;
	char	*new_str;

	start = 0;
	end = ft_strlen(s);
	while (s[start] == c)
		start++;
	while (s[end - 1] == c)
		end--;
	if (end == 0)
		return (NULL);
	new_str = ft_strnew(end - start + 1);
	if (new_str == NULL)
		return (NULL);
	ft_strncpy(new_str, &s[start], end - start);
	return (new_str);
}

char				**ft_strsplit(char const *s, char c)
{
	char			**arr;
	const	char	*ptr;
	size_t			arr_i;
	size_t			words_cnt;

	words_cnt = ft_get_words_cnt(s, c) + 1;
	arr = (char **)malloc(sizeof(char *) * words_cnt);
	if (arr == NULL)
		return (NULL);
	arr_i = 0;
	ptr = ft_strtrimc(s, c);
	while (arr_i < words_cnt && words_cnt != 1 && ptr != NULL)
	{
		arr[arr_i] = ft_create_word(ptr, c);
		ptr = ft_get_next_word_pos(ptr, c);
		if (ptr == NULL)
		{
			arr_i++;
			break ;
		}
		arr_i++;
	}
	arr[arr_i] = NULL;
	return (arr);
}
