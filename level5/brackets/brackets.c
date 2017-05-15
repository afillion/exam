#include <unistd.h>

void    put_char(char c)
{
	write(1, &c, 1);
}

void    put_str(char *s)
{
	while (*s)
		put_char(*s++);
}

int     main(int ac, char **av)
{
	int pr;
	int pl;
	int cr;
	int cl;
	int ar;
	int al;
	int i;
	int j;
	int	pos;

	i = 1;
	if (ac == 1)
		put_char('\n');
	else
	{
		while (i < ac)
		{
			pr = 0;
			pl = 0;
			cr = 0;
			cl = 0;
			ar = 0;
			al = 0;
			j = 0;
			while(av[i][j])
			{
				if (av[i][j] == '(')
					pr++;
				else if (av[i][j] == ')')
					pl++;
				else if (av[i][j] == '[')
					cr++;
				else if (av[i][j] == ']')
					cl++;
				else if (av[i][j] == '{')
					ar++;
				else if (av[i][j] == '}')
					al++;
				else {
					av[i][j] = '.';
				}
				j++;
			}
			if (pr != pl || cr != cl || ar != al)
			{
				put_str("Error\n");
			}
			else
			{
				if (pr == 0 && cr == 0 && ar == 0)
					put_str("OK\n");
				else {
					j = 0;
					while (av[i][j] != '\0') {
						if (av[i][j] == ')' || av[i][j] == ']' || av[i][j] == '}') {
							pos = j;
							if (av[i][j] == ')') {
								av[i][j] = '.';
								while (pos--) {
									if (av[i][pos] == '[' || av[i][pos] == '{') {
										break;
									}
									else if (av[i][pos] == '(') {
										av[i][pos] = '.';
										break;
									}
								}
							}
							else if (av[i][j] == ']') {
								av[i][j] = '.';
								while (pos--) {
									if (av[i][pos] == '(' || av[i][pos] == '{') {
										break;
									}
									else if (av[i][pos] == '[') {
										av[i][pos] = '.';
										break;
									}
								}
							}
							if (av[i][j] == '}') {
								av[i][j] = '.';
								while (pos--) {
									if (av[i][pos] == '[' || av[i][pos] == '(') {
										break;
									}
									else if (av[i][pos] == '{') {
										av[i][pos] = '.';
										break;
									}
								}
							}
						}
						j++;
					}
					j = 0;
					while(av[i][j])
					{
						if (av[i][j] != '.') {
							put_str("Error\n");
							break;
						}
						else if (av[i][j+1] == '\0') {
							put_str("OK\n");
							break;
						}
						j++;
					}
				}
			}
			i++;
		}
	}
	return (0);
}
