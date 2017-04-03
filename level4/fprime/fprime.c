#include <stdio.h>
#include <stdlib.h>

int	main(int ac, char **av)
{
	int nb;
	int i;

	if (ac == 2)
	{
		if (av[1][0] == '\0')
		{
			printf("\n");
			return (0);
		}
		nb = atoi(av[1]);
		if (nb == 1)
		{
			printf("1\n");
			return (0);
		}
		while (1)
		{
			i = 1;
			while (++i <= nb)
			{
				if (nb % i == 0)
				{
					printf("%d", i);
					nb = nb / i;
					break ;
				}
			}
			if (nb == 1)
			{
				break ;
			}
			else
			{
				printf("*");
			}
		}
	}
	printf("\n");
	return (0);
}
