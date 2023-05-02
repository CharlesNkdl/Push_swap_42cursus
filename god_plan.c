#include "libft.h"
#include "push_swap.h"

/*void	god_plan(t_bucket **a, t_bucket **b)
{
	pa(b, a);
	pa(b, a);
	ft_verif(b);
	while (check(a,b) != 0)
	{
		gp_next(a, b);
	}


}

void	gp_next(t_bucket **a, t_bucket **b)
{
	ins_count(a,b);


}

int	ins_count(t_bucket **a, t_bucket **b)
{
	t_ins	ins;
	t_ins	best;

	initializeins(&ins);
	initializeins(&best);
	next_best(a, b, &ins, &best);




}*/

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

void	inicpy(t_ins	*ins, t_ins		*best)
{
	best->ra = ins->ra;
	best->rb = ins->rb;
	best->rra = ins->rra;
	best->rrb = ins->rrb;
	best->copy = ins->copy;
	return ;
}

/*void	ft_verif(t_bucket **b)
{
	if (getvaluefirst(b) > getvaluelast(b))
		sb(b, 1);
	else
		return ;
}

void	next_best(t_bucket	**a, t_bucket **b, t_ins *ins, t_ins *best)
{



}*/
