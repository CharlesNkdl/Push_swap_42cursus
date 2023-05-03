#include "libft.h"
#include "push_swap.h"

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

void	initializeins(t_ins *ins)
{
	ins->ra = 0;
	ins->rb = 0;
	ins->rra = 0;
	ins->rrb = 0;
	ins->copy = 0;
}

void	initializeinsneg(t_ins *ins)
{
	ins->ra = -1;
	ins->rb = -1;
	ins->rra = -1;
	ins->rrb = -1;
	ins->copy = 0;
}

int	inicount(t_ins	ins)
{
	int	count;

	count = 0;
	while (ins.ra != 0 && ins.rb != 0)
	{
		ins.ra -= 1;
		ins.rb -= 1;
		count ++;
	}
	while (ins.rra != 0 && ins.rrb != 0)
	{
		ins.rra -= 1;
		ins.rrb -= 1;
		count ++;
	}
	count += ins.ra;
	count += ins.rb;
	count += ins.rra;
	count += ins.rrb;
	return (count);
}
