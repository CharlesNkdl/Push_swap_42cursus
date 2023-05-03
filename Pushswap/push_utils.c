#include "libft.h"
#include "push_swap.h"

int	check(t_bucket **a, t_bucket **b)
{
	t_bucket	*ptr;
	int	temp;

	if (*b)
		return (0);
	ptr = *a;
	while (ptr->next)
	{
		temp = ptr-> content;
		ptr = ptr->next;
		if (temp > ptr->content)
			return (0);
	}
	return (1);
}

void	ft_bucketadd_back(t_bucket **lst, t_bucket *new)
{
	t_bucket	*ptr;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	ptr = *lst;
	ptr = ft_bucketlast(*lst);
	ptr->next = new;
	new->next = NULL;
}

t_bucket	*ft_bucketnew(int content)
{
	t_bucket	*list;

	list = malloc(sizeof(t_bucket));
	if (!list)
		return (NULL);
	list->content = content;
	list->next = NULL;
	return (list);
}

t_bucket	*ft_bucketlast(t_bucket *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

t_bucket	*ft_bucketbeflast(t_bucket *stack)
{
	while (stack && stack->next && stack->next->next != NULL)
		stack = stack->next;
	return (stack);
}
