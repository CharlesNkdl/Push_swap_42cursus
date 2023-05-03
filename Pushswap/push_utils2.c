#include "libft.h"
#include "push_swap.h"

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

	ptr = ft_bucketlast(*a);
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
	while (ptr->next)
	{
		ptr = ptr->next;
		count++;
		if (!ptr)
			return (count);
		if (ptr->content == find)
			return (count);
	}
	return (count);
}

void	sortthreea(t_bucket **a)
{
	t_bucket *ptr;
	int	value1;
	int	value2;
	int value3;

	ptr = *a;
	value1 = ptr->content;
	ptr = ptr->next;
	value2 = ptr->content;
	ptr = ptr->next;
	value3 = ptr->content;
	if (value1 < value2 && value1 < value3 && value2 < value3)
		return ;
	if (value1 > value2 && value1 > value3 && value2 > value3)
	{
		sa(a, 1);
		rra(a, 1);
		return ;
	}
	if (value1 > value2 && value1 < value3 && value2 < value3)
	{
		sa(a, 1);
		return ;
	}
	if (value1 > value2 && value2 < value3 && value1 > value3)
	{
		ra(a,1);
		return ;
	}
	if (value1 < value2 && value1 < value3 && value2 > value3)
	{
		sa(a, 1);
		ra(a, 1);
		return ;
	}
	if (value1 < value2 && value2 > value3 && value1 > value3)
	{
		rra(a, 1);
		return ;
	}
}
