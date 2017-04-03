#include <stdlib.h>

int		ft_intlen(int n)
{
	int i;

	i = 1;
	if (n < 0)
	{
		i++;
		n *= -1;
	}
	while ((n /= 10) > 0)
		i++;
	return (i);
}

int		ft_pow(int a, int b)
{
	int	i;
	int	tmp;

	i = 1;
	tmp = a;
	while (i < b)
	{
		tmp *= a;
		i++;
	}
	a = tmp;
	return (a);
}

char	*ft_itoa(int nbr)
{
	char	*s;
	int		i;
	int		wnbr;
	int		tmp;

	if (nbr == -2147483648)
	{
		s = (char*)malloc(sizeof(char) * 12);
		s = "-2147483648\0";
		return (s);
	}
	i = 0;
	wnbr = ft_intlen(nbr);
	s = (char*)malloc(sizeof(char) * wnbr + 1);
	s[wnbr + 1] = '\0';
	if (nbr < 0)
	{
		s[i] = '-';
		wnbr--;
		i++;
		nbr *= -1;
	}
	tmp = nbr;
	while (--wnbr > 0)
	{
		s[i] = (tmp / (ft_pow(10, wnbr))) + 48;
		tmp = tmp % ft_pow(10, wnbr);
		i++;
	}
	s[i] = (nbr % 10) + 48;
	return (s);
}
#include <stdio.h>
int main(void)
{
	printf("%s\n", ft_itoa(-2147483648));
	return (0);
}
