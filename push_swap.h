#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_bucket
{
	int			content;
	struct s_bucket	*next;
}			t_bucket;

typedef struct s_max
{
	int	v1;
	int	v2;
	int	v3;
}			t_max;

void print_stack(t_bucket *stack);
void    ft_miracle(int *stack, int argc);
int *ft_checkdoubl(int argc, char **argv);
void ft_check(int argc, char **argv);
void ft_error(void);
void	ft_bucketadd_back(t_bucket **lst, t_bucket *new);
t_bucket	*ft_bucketnew(int content);
t_bucket	*ft_bucketlast(t_bucket *lst);
void	ft_bucketadd_back(t_bucket **lst, t_bucket *new);
int    sa(t_bucket **a, int version);
int    sb(t_bucket **a, int version);
void    ss(t_bucket **a, t_bucket **b);
int    pa(t_bucket **a,t_bucket **b);
int    pb(t_bucket **a,t_bucket **b);
int    ra(t_bucket **a, int version);
int    rb(t_bucket **a, int version);
void    rr(t_bucket **a, t_bucket **b);
int    rra(t_bucket **a,int version);
int    rrb(t_bucket **a, int version);
void    rrr(t_bucket **a,t_bucket **b);
t_bucket	*ft_bucketbeflast(t_bucket *stack);
int	ft_bucketsize(t_bucket *lst);
int	check(t_bucket **a, t_bucket **b);
void	algo(t_bucket **a, t_bucket **b);
void	sortthreea(t_bucket **a);
int	getvaluefirst(t_bucket **a);
void	reimplant(t_bucket **a, t_bucket **b);
int	getvaluelast(t_bucket **a);
void	fillmax(t_max	*max, t_bucket	**a);
void	comparemax(t_bucket **a,t_bucket **b, t_max *max);
void	optimize(int	max, t_bucket	**b);
int	findvalue(int find, t_bucket **a);
int	get_max(t_bucket **b);

#endif
