#include "libft.h"

void	ft_print_lst(t_list *lst)
{
	while (lst)
	{
		printf("%s\n", lst->content);
		lst = lst->next;
	}
}

int main(void)
{
	t_list *list;

	list = ft_lstnew("test");
	ft_lstadd_front(&list, ft_lstnew("aaa"));
	ft_lstadd_front(&list, ft_lstnew("bbb"));
	ft_lstadd_front(&list, ft_lstnew("ccc"));
	ft_lstadd_front(&list, ft_lstnew("ddd"));
	ft_print_lst(list);
	
}
