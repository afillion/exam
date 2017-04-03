#include <unistd.h>

int		ft_atoi(char *str)
{
	int		i;
	int		nbr;

	i = 0;
	nbr = 0;
	if (str[i] == '-')
		return (0);
	while (str[i] != '\0')
	{
		if (!(str[i] >= 48 && str[i] <= 57))
			return (0);
		nbr = nbr * 10;
		nbr = nbr + (str[i] - 48);
		i++;
	}
	return (nbr);
}

void	ft_putnbr(int n)
{
	char c;

	if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
	{
		c = n + '0';
		write(1, &c, 1);
	}
}

int		ft_is_prim(int n)
{
	int	i;

	i = 2;
	while (i < n)
	{
		if (n % i == 0)
			return (0);
		i++;
	}
	return (1);
}

void	ft_add_prim_sum(int n)
{
	int	i;
	int	count;

	i = 2;
	count = 0;
	while (i <= n)
	{
		if (ft_is_prim(i))
			count = count + i;
		i++;
	}
	ft_putnbr(count);
}

int	main(int ac, char **av)
{
	if (ac == 2)
		ft_add_prim_sum(ft_atoi(av[1]));
	else
		write(1, "0", 1);
	write(1, "\n", 1);
	return (0);
}
