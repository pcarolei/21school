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
	if (c >= 48 && c <= 57)
		return ((int)(c - 48));
	if (c >= 'a' && c <= 'f')
		return (c - 87);
	if (c >= 'A' && c <= 'F')
		return (c - 55);
	return (0);
}

int	log_if(char c, unsigned int base)
{
	if (base <= 10)
	{
		if (c >= '0' && c <= ('0' + (int)base - 1))
			return (1);
		else
			return (0);
	}
	if (c >= '0' && c <= '9')
		return (1);
	if (c >= 'a' && c <= ('a' + ((int)base - 11)))
		return (1);
	if (c >= 'A' && c <= ('A' + ((int)base - 11)))
		return (1);
	return (0);
}

int	ft_atoi_base(const char *nbr, unsigned int base)
{
	int				sign;
	int				len;
	int				res;
	unsigned int	i;

	if ((nbr[0] == '-' || nbr[0] == '+') && (nbr[1] == '-' || nbr[1] == '+'))
		return (0);
	sign = (nbr[0] == '-') ? (-1) : (1);
	len = ft_strlen(nbr) - 1;
	i = 1;
	res = 0;
	while (len >= 0 && nbr[len] != '-' && nbr[len] != '+')
	{
		if (log_if(nbr[len], base))
		{
			res += (int)(char_to_int(nbr[len]) * i);
			i *= base;
		}
		else
			break ;
		len--;
	}
	return (sign * res);
}
