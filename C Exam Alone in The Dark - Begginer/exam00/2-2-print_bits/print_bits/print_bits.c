#include <unistd.h>

int		power_of_two(int i)
{
	int	res;

	res = 1;
	while (i > 0)
	{
		res *= 2;
		i--;
	}
	return (res);
}

void	print_bits(unsigned char octet)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if (octet - power_of_two(i) >= 0)
		{
			octet -= power_of_two(i);
			write(1, "1", 1);
		}
		else
			write(1, "0", 1);
		i--;
	}
}
