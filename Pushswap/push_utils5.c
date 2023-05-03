#include "libft.h"
#include "push_swap.h"

void	inicpy(t_ins	*ins, t_ins		*best)
{
	best->ra = ins->ra;
	best->rb = ins->rb;
	best->rra = ins->rra;
	best->rrb = ins->rrb;
	best->copy = ins->copy;
	return ;
}

int	next_three(t_bucket **a)
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
		return (1);
	else
		return (0);
}

int	next_threesum(t_bucket **a)
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
	return (value1 + value2 + value3);
}

int	sortedb(t_bucket **a)
{
	t_bucket	*ptr;
	int	temp;

	ptr = *a;
	while (ptr->next)
	{
		temp = ptr-> content;
		ptr = ptr->next;
		if (temp < ptr->content)
			return (0);
	}
	return (1);
}

void	free_bucket(t_bucket **bucket)
{
	t_bucket	*tmp;

	if (!bucket || !(*bucket))
		return ;
	while (*bucket)
	{
		tmp = (*bucket)->next;
		free(*bucket);
		*bucket = tmp;
	}
	*bucket = NULL;
}
