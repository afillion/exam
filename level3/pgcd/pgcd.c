#include <stdio.h>
#include <stdlib.h>

void ft_pgcd(int a, int b)
{
	int r;

	while (b != 0)
	{
		r = a % b;
		a = b;
		b = r;
	}
	printf("%d\n", a);
}

int main(int ac, char **av)
{
	if (ac == 3)
	{
		ft_pgcd(atoi(av[1]), atoi(av[2]));
	}
	else
		printf("%c", '\n');
	return (0);
}
