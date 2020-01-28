#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

char	shift_letter(char c)
{
	if ((c >= 'A' && c < 'Z') || (c >= 'a' && c < 'z'))
		return (c + 1);
	if (c == 'Z')
		return ('A');
	if (c == 'z')
		return ('a');
	return (c);
}

void	rotone(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(shift_letter(str[i]));
		i++;
	}
	ft_putchar('\n');
}

int		main(int ac, char **av)
{
	if (ac != 2)
	{
		ft_putchar('\n');
		return (0);
	}
	rotone(av[1]);
	return (0);
}
