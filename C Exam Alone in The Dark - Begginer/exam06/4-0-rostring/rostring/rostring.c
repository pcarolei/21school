#include <unistd.h>
#include <stdlib.h>

int		ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		get_next_word_pos(char *str, int cur_pos)
{
	int	nxt_pos;

	nxt_pos = cur_pos;
	while ((str[nxt_pos] != ' ') && (str[nxt_pos] != '\t')
								 && (str[nxt_pos] != '\0'))
	{
		if (cur_pos == 0)
			return (nxt_pos);
		else
			nxt_pos++;
	}
	while (((str[nxt_pos] == ' ') || (str[nxt_pos] == '\t'))
			&& (str[nxt_pos] != '\0'))
		nxt_pos++;
	if (str[nxt_pos] != '\0')
		return (nxt_pos);
	return (-1);
}

int		count_words(char *str)
{
	int	pos;
	int	cnt;

	cnt = 0;
	pos = get_next_word_pos(str, 0);
	if (pos >= 0)
		cnt++;
	while ((pos = get_next_word_pos(str, pos + 1)) > 0)
		cnt++;
	return (cnt);
}

char	*extract_word(char *str, int word_pos)
{
	char	*word;
	int		len;
	int		i;
	int		j;

	len = 0;
	i = word_pos;
	while ((str[i] != ' ') && (str[i] != '\t') && (str[i] != '\0'))
	{
		i++;
		len++;
	}
	word = (char *)malloc(len + 1);
	word[len] = '\0';
	i = word_pos;
	j = 0;
	while (len > 0)
	{
		word[j] = str[i];
		j++;
		i++;
		len--;
	}
	return (word);
}

char	**create_word_arr(char *str)
{
	char	**word_arr;
	int		pos;
	int		cnt;
	int		i;

	cnt = count_words(str);
	if (cnt == 0)
		return (NULL);
	word_arr = (char **)malloc(sizeof(char *) * (cnt + 1));
	word_arr[cnt] = NULL;
	i = 0;
	pos = get_next_word_pos(str, 0);
	word_arr[0] = extract_word(str, pos);
	i++;
	while ((pos = get_next_word_pos(str, pos + 1)) > 0)
	{
		word_arr[i] = extract_word(str, pos);
		i++;
	}
	return (word_arr);
}

int		get_word_arr_len(char **word_arr)
{
	int	i;

	i = 0;
	while (word_arr[i])
		i++;
	return (i);
}

void	print_result(char **word_arr)
{
	int	len;
	int	i;

	if (word_arr == NULL)
	{
		write(1, "\n", 1);
		return ;
	}
	len = get_word_arr_len(word_arr);
	i = 1;
	while (i < len)
	{
		write(1, word_arr[i], ft_strlen(word_arr[i]));
		write(1, " ", 1);
		i++;
	}
	write(1, word_arr[0], ft_strlen(word_arr[0]));
	write(1, "\n", 1);
}

void	rostring(char *str)
{
	char	**word_arr;

	word_arr = create_word_arr(str);
	print_result(word_arr);
}

int		main(int ac, char **av)
{
	if (ac < 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	rostring(av[1]);
	return (0);
}
