int	max(int *tab, unsigned int len)
{
	int	max;
	int	i;

	if (!tab || len == 0)
		return (0);
	max = -2147483648;
	i = 0;
	while (i < len)
	{
		if (tab[i] > max)
			max = tab[i];
		i++;
	}
	return (max);
}
