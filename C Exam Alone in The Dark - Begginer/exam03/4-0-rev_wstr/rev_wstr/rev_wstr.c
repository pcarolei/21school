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

char	*get_first_word(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	return (&str[i]);
}

char	*get_next_word(char *str)
{
	int	i;

	i = 0;
	while (str[i] != ' ' && str[i] != '\t' && str[i] != '\0')
		i++;
	if (str[i] != ' ' && str[i] != '\t')
		return (NULL);
	return (&str[i + 1]);
}

int		count_words(char *str)
{
	int		count;
	char	*cur_word;

	count = 0;
	cur_word = get_first_word(str);
	while (cur_word)
	{
		count++;
		cur_word = get_next_word(cur_word);
	}
	return (count);
}

char	**reverse_words_arr(char **words, int words_cnt)
{
	char	**rev_words;
	int		i;

	rev_words = (char **)malloc(sizeof(char *) * words_cnt);
	i = 0;
	while (i < words_cnt)
	{
		rev_words[i] = words[words_cnt - 1 - i];
		i++;
	}
	free(words);
	return (rev_words);
}

void	print_reversed_words_arr(char **words, int words_cnt)
{
	int		i;
	char	**rev_words;

	i = 0;
	rev_words = reverse_words_arr(words, words_cnt);
	while (i < words_cnt - 1)
	{
		write(1, rev_words[i], ft_strlen(rev_words[i]));
		write(1, " ", 1);
		i++;
	}
	write(1, rev_words[i], ft_strlen(rev_words[i]));
	write(1, "\n", 1);
}

char	*extract_word(char *str)
{
	int		size;
	int		i;
	char	*word;

	size = 0;
	while (str[size] != ' ' && str[size] != '\0')
		size++;
	word = (char *)malloc(size + 1);
	word[size] = '\0';
	i = 0;
	while (i < size)
	{
		word[i] = str[i];
		i++;
	}
	return (word);
}

void	rev_wstr(char *str)
{
	int		words_cnt;
	int		i;
	char	*cur_word;
	char	**words;

	words_cnt = count_words(str);
	i = 0;
	words = (char **)malloc(sizeof(char *) * words_cnt);
	while (i < words_cnt)
	{
		if (i == 0)
			cur_word = get_first_word(str);
		else
			cur_word = get_next_word(cur_word);
		words[i] = extract_word(cur_word);
		i++;
	}
	print_reversed_words_arr(words, words_cnt);
}

int		main(int ac, char **av)
{
	if (ac != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	rev_wstr(av[1]);
	return (0);
}
