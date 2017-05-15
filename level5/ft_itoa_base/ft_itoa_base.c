#include <stdlib.h>
#define ABS(n) ((n) < 0 ? -(n) : (n))

void	solve(int value, int b, char *ret, int *pos)
{
	char base[] = "0123456789ABCDEF";

	if (value <= -b || value >= b)
	  solve((value / b), b, ret, pos);
	ret[(*pos)++] = base[ABS(value % b)];	
}

char	*ft_itoa_base(int value, int base)
{
	char	*ret;
	int		pos;

	if (base < 2 || base > 16 || !(ret = malloc(sizeof(char) * 35)))
		return (NULL);
	pos = 0;
	if (base == 10 && value < 0)
		ret[pos++] = '-';
	solve(value, base, ret, &pos);
	ret[pos] = '\0';
	return (ret);
}
