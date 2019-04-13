#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new_lst;

	new_lst = (t_list *)malloc(sizeof(t_list));
	if (new_lst == NULL)
		return (NULL);
	new_lst->next = NULL;
	if (content == NULL)
	{
		new_lst->content = NULL;
		new_lst->size = 0;
		return (new_lst);
	}
	new_lst->content = malloc(content_size);
	ft_memcpy(new_lst->content, content, content_size);
	new_lst->size = content_size;
	return (new_lst);
}		
