#include <stdlib.h>
#include <stdio.h>

int	prime_check(int prime)
{
	int	i;

	if (prime <= 7)
		return (prime == 2 || prime == 3 || prime == 5 || prime == 7);
	i = 8;
	while (i * i < prime)
	{
		if (prime % i == 0)
			return (0);
		i += 2;
	}
	return (1);
}

int	get_next_prime(int num, int start)
{
	int	prime;

	prime = start + 1;
	while (prime <= num)
	{
		while (!prime_check(prime))
			prime++;
		if (num % prime == 0)
			return (prime);
		else
			prime++;
	}
	if (prime <= num)
		return (prime);
	return (0);
}

int		rem_prime_from_num(int num, int prime)
{
	while (num % prime == 0)
	{
		printf("%d", prime);
		num = num / prime;
		if (num % prime == 0)
			printf("*");
	}
	return (num);
}

void	print_primes(int num)
{
	int	cur_prime;

	if (num == 1)
	{
		printf("1\n");
		return ;
	}
	cur_prime = 1;
	while (cur_prime > 0)
	{
		if (num != 1)
		{
			cur_prime = get_next_prime(num, cur_prime);
			num = rem_prime_from_num(num, cur_prime);
		}
		if (num == 1)
			break ;
		else
			printf("*");
	}
	printf("\n");
}

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		printf("\n");
		return (1);
	}
	print_primes(atoi(av[1]));
	return (0);
}
