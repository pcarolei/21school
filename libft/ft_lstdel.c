#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*ptr;
	t_list	*ptr_copy;

	ptr = *alst;
	ptr_copy = ptr;
	while (ptr)
	{
		ft_lstdelone(&ptr_copy, del);
		ptr = ptr->next;
		ptr_copy = ptr;
	}
	free(alst);
	alst = NULL;
}
