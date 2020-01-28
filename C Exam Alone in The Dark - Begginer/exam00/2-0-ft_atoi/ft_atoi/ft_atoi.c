int	ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	char_to_int(char c)
{
	return ((int)(c - 48));
}

int	ft_atoi(const char *str)
{
	int	sign;
	int	len;
	int	i;
	int	res;

	if ((str[0] == '-' || str[0] == '+') && (str[1] == '-' || str[1] == '+'))
		return (0);
	sign = (str[0] == '-') ? (-1) : (1);
	len = ft_strlen(str) - 1;
	i = 1;
	res = 0;
	while (len >= 0 && str[len] != '-' && str[len] != '+')
	{
		res += char_to_int(str[len]) * i;
		i *= 10;
		len--;
	}
	return (sign * res);
}
