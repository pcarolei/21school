#include <stdlib.h>
#include "list.h"

int		search_dup_in_tab(int tab[1000], int size)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (j < size)
	{
		while (i < size)
		{
			if (tab[i] == tab[j])
				return (1);
			i++;
		}
		j++;
		i = j + 1;
	}
	return (0);
}

int		cycle_detector(const t_list *list)
{
	int		tab[1000];
	int		i;
	t_list	*ptr;

	if (!list)
		return (0);
	ptr = (t_list *)list;
	i = 0;
	while (ptr)
	{
		tab[i] = (int)ptr;
		ptr = ptr->next;
		if (search_dup_in_tab(tab, i))
			return (1);
		i++;
	}
	return (0);
}
