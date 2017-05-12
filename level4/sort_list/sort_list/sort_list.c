#include "list.h"

t_list	*sort_list(t_list *lst, int (*cmp)(int, int))
{
	int		swap;
	t_list	*tmp;

	tmp = lst;
	while (lst->next)
	{
		if (cmp(lst->data, lst->next->data) == 0)
		{
			swap = lst->data;
			lst->data = lst->next->data;
			lst->next->data = swap;
			lst = tmp;
		}
		else //else comme ca si cmp()==0 on avance pas dans la chaine et on recheck 
			lst = lst->next;
	}
	lst = tmp; //on remet la list au debut sinon on est sur le dernier maillon !
	return (lst);
}
