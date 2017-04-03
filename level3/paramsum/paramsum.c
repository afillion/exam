#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
		ft_putchar('0' + n);

}

int	main(int ac, char **av)
{
	ft_putnbr(ac - 1);
	ft_putchar('\n');
	(void)av;
	return (0);
}
