#include "libft.h"
#include "push_swap.h"

void	algo(t_bucket **a, t_bucket **b)
{
	//t_bucket	*ptr;
	t_max	maxa;
	int	min;
	int	max;

	fillmax(&maxa, a);
	//printf("%d", maxa.v1);
	//printf("%d", maxa.v2);
	//printf("%d", maxa.v3);
	//ptr = *a;
	min = 0;
	max = 0;
	if (check(a,b) == 1)
		return ;
	while (getvaluefirst(a) > maxa.v3)
		pa(b, a);
	pa(b, a);
	while (ft_bucketsize(*a) > 3)
	{
		min = findvalue(get_min(a), a);
		if (min > ft_bucketsize(*a) / 2)
			min = ft_bucketsize(*a) - min;
		max = findvalue(get_max(a), a);
		if (max > ft_bucketsize(*a) / 2)
			max = ft_bucketsize(*a) - max;
		if (min <= max)
		{
			optimize(get_min(a), a);
			pa(b, a);
			rb(b, 1);
		}
		else
		{
			optimize(get_max(a), a);
			pa(b, a);
		}
		//rb(b, 1);
		//comparemax(a, b, &maxa);
		if (ft_bucketsize(*b) == 3)
			sortthreeb(b);
		//ptr = *a;
	}
	sortthreea(a);
	reimplant(a, b);
	return ;
}

void	fillmax(t_max	*max, t_bucket	**a)
{
	t_bucket	*ptr;
	int	temp;
	int	temp2;
	int	loop;

	max->v1 = -2147483648;
	max->v2 = -2147483648;
	max->v3 = -2147483648;
	temp = 0;
	temp2 = 0;
	loop = 0;
	ptr = *a;
	while (loop != 3)
	{
		while (ptr)
		{
			if (ptr->content > max->v1)
			{
				temp = max->v1;
				max->v1 = ptr->content;
				temp2 = max->v2;
				max->v2 = temp;
				max->v3 = temp2;
			}
			else if (ptr->content > max->v2 && ptr->content < max->v1)
			{
				temp = max->v2;
				max->v2 = ptr->content;
				max->v3 = temp;
			}
			else if (ptr->content > max->v3 && ptr->content < max->v2)
				max->v3 = ptr->content;
			ptr = ptr->next;
		}
		ptr = *a;
		loop++;
	}
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

void	sortthreeb(t_bucket **a)
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
	{
		sb(a, 1);
		rrb(a, 1);
		return ;
	}
	if (value1 > value2 && value1 > value3 && value2 > value3)
	{
		return ;
	}
	if (value1 > value2 && value1 < value3 && value2 < value3)
	{
		rrb(a, 1);
		return ;
	}
	if (value1 > value2 && value2 < value3 && value1 > value3)
	{
		sb(a, 1);
		rb(a, 1);
		return ;
	}
	if (value1 < value2 && value1 < value3 && value2 > value3)
	{
		rb(a, 1);
		return ;
	}
	if (value1 < value2 && value2 > value3 && value1 > value3)
	{
		sb(a, 1);
		return ;
	}
}

void	comparemax(t_bucket **a,t_bucket **b, t_max *max)
{
	t_bucket	*ptr;
	int	last;
	int	first;

	ptr = *a;
	if (ptr->content < max->v3)
	{
		if (ptr->content < getvaluefirst(b) && getvaluelast(b) < getvaluefirst(b))
		{
			if (ptr->content > getvaluelast(b) && ft_bucketsize(*b) > 2)
			{
				rrb(b, 1);
				pa(b, a);
				//rb(b, 1);
				//rb(b, 1);
			}
			else
			{
				pa(b, a);
				sb(b, 1);
			}
		}
		else if ((ptr->content > getvaluefirst(b) && ft_bucketsize(*b) > 2))
		{
			last = getvaluelast(b);
			first = getvaluefirst(b);
			if (ptr->content > last && (last > first))
			{
				rb(b, 1);
				pa(b,a);
			}
		}
		else
			pa(b, a);
		return ;
	}
	else if (ptr->content >= max->v3)
	{
		ra(a, 1);
		return ;
	}
}

void	reimplant(t_bucket **a, t_bucket **b)
{
	int	count;
	int	min;
	int max;

	count = 0;
	while (ft_bucketsize(*b) != 0)
	{
		min = findvalue(get_min(b), b);
		if (min > ft_bucketsize(*b) / 2)
			min = ft_bucketsize(*b) - min;
		max =  findvalue(get_max(b), b);
		if (max > ft_bucketsize(*b) / 2)
			max = ft_bucketsize(*b) - max;
		if (min < max)
		{
			optimize(get_min(b), b);
			pb(a, b);
			ra(a, 1);
			count++;
		}
		else
		{
			optimize(get_max(b), b);
			pb(a, b);
		}
	}
	while (count != 0)
	{
		rra(a, 1);
		count--;
	}
	return ;
}

void	optimize(int	max, t_bucket	**b)
{
	t_bucket	*ptr;
	int	size;

	if (max == -2147483648)
		return ;
	ptr = *b;
	size = ft_bucketsize(ptr);
	if (findvalue(max, b) == 0)
		return ;
	if (findvalue(max, b) > (size / 2))
	{
		while (ptr->content != max)
		{
			rrb(b, 1);
			ptr = *b;
			if (!ptr || ptr->content == max)
				return ;
		}
	}
	if (findvalue(max, b) <= (size / 2))
	{
		while (ptr->content != max)
		{
			rb(b, 1);
			ptr = *b;
			if (!ptr || ptr->content == max)
				return ;
		}
	}
}

int	get_max(t_bucket **b)
{
	t_bucket	*ptr;
	int	find;

	ptr = *b;
	find = getvaluefirst(b);
	while (ptr)
	{
		ptr = ptr->next;

		if (!ptr)
			return (find);
		if (ptr->content > find)
			find = ptr->content;
	}
	return (find);
}

int	get_min(t_bucket **b)
{
	t_bucket	*ptr;
	int	find;

	ptr = *b;
	find = getvaluefirst(b);
	while (ptr)
	{
		ptr = ptr->next;

		if (!ptr)
			return (find);
		if (ptr->content < find)
			find = ptr->content;
	}
	return (find);
}
