#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	**new_lst;
	t_list	*ptr;
	t_list	*elem;

	while (ptr)
	{
		elem = f(ptr);
		ft_lstadd(new_lst, elem);
		ptr = ptr->next;
	}
	return (new_lst);
}
