#include <stdlib.h>
#include <unistd.h>

int		ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		ft_strlen_word(char *str)
{
	int	i;

	i = 0;
	while (str[i] != ' ' && str[i] != '\t' && str[i] != '\0')
		i++;
	return (i);
}

char	*get_next_word(char *str)
{
	int	i;

	i = 0;
	while (str[i] != ' ' && str[i] != '\t' && str[i] != '\0')
		i++;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i] == '\0')
		return (NULL);
	return (&(str[i]));
}

char	*copy_word(char *str)
{
	int		i;
	char	*word;

	i = 0;
	word = (char *)malloc(ft_strlen_word(str));
	while (i < ft_strlen_word(str))
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

void	words_arr_init(char **words_arr, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		words_arr[i] = NULL;
		i++;
	}
}

void	rev_wstr(char *str, int len)
{
	char	*words_arr[len];
	char	*str_ptr;
	int		i;

	str_ptr = str;
	words_arr_init((char **)words_arr, len);
	i = 0;
	while (str_ptr && i < 4)
	{
		words_arr[i] = copy_word(str_ptr);
		str_ptr = get_next_word(str_ptr);
		i++;
	}
	i = 0;
	while (words_arr[i])
	{
		i++;
	}
	i--;
	while (i >= 0)
	{
		write(1, words_arr[i], ft_strlen(words_arr[i]));
		if (i != 0)
			write(1, " ", 1);
		i--;
	}
	return ;
}

int		main(int ac, char **av)
{
	if (ac != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	rev_wstr(av[1], ft_strlen(av[1]));
	return (0);
}

/*
 * Создаю стек. Иду в цикле по строке, встречаю слово - кладу на стек
 * После завершения этого процесса, маллочу ровно столько же символов,
 * сколько было в начале и заполняю строку
*/
