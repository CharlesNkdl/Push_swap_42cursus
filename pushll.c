#include "libft.h"
#include "push_swap.h"

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

int	ft_bucketsize(t_bucket *lst)
{
	int	count;

	count = 0;
	if (!lst)
		return (count);
	while (lst)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}

int	getvaluefirst(t_bucket **a)
{
	t_bucket	*ptr;

	ptr = *a;
	if (!ptr)
		return (0);
	return (ptr->content);
}

int	getvaluelast(t_bucket **a)
{
	t_bucket	*ptr;

	ptr = *a;
	ptr = ft_bucketlast(ptr);
	return (ptr->content);
}

int	findvalue(int find, t_bucket **a)
{
	int	count;
	t_bucket	*ptr;

	ptr = *a;
	count = 0;
	if (ptr->content == find)
		return (count);
	if (!ptr)
		return (count);
	while (ptr)
	{
		ptr = ptr->next;
		count++;
		if (!ptr)
			return (count);
		if (ptr->content == find)
			return (count);
	}
	return (0);
}
