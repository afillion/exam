#include <unistd.h>

void	put_char(char c)
{
	write(1, &c, 1);
}

void	put_word(char *s)
{
	while(*s && *s != ' ' && *s != '\t')
		write(1, s++, 1);
}

int	main(int ac, char **av)
{
	int	i;

	i = 0;
	if (ac >= 2)
	{
		while (av[1][i])
		{
			while(av[1][i] && (av[1][i] == ' ' || av[1][i] == '\t'))
				i++;
			while(av[1][i] && (av[1][i] != ' ' && av[1][i] != '\t'))
				i++;
			while(av[1][i] && (av[1][i] == ' ' || av[1][i] == '\t'))
				i++;
			put_word(av[1] + i);
			if (av[1][1] != '\0')
				put_char(' ');
		}
		i = 0;
		while(av[1][i] && (av[1][i] == ' ' || av[1][i] == '\t'))
			i++;
		put_word(av[1] + i);
	}
	write(1, "\n", 1);
	return (0);
}
