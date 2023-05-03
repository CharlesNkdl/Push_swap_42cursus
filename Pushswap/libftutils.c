#include "push_swap.h"
#include "libft.h"

long long	ft_atoi(char const *nptr)
{
	int	count;
	int	countsignneg;
	long long	result;

	count = 0;
	countsignneg = 1;
	result = 0;
	while ((nptr[count] >= 9 && nptr[count] <= 13) || (nptr[count] == 32))
		count++;
	if (nptr[count] == 45 || nptr[count] == 43)
	{
		if (nptr[count] == 45)
			countsignneg *= -1;
		count ++;
	}
	while (nptr[count] >= 48 && nptr[count] <= 57)
	{
		result = result * 10 + (nptr[count] - 48);
		count ++;
	}
	return (result * countsignneg);
}

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putendl_fd(char const *s, int fd)
{
	if (s != NULL)
	{
		ft_putstr_fd(s, fd);
		ft_putchar_fd('\n', fd);
	}
}

void	ft_putstr_fd(char const *s, int fd)
{
	if (s != NULL)
		write(fd, s, ft_strlen(s));
}

