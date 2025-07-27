#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_swap(char *c1, char *c2)
{
	char tmp;

	tmp = *c1;
	*c1 = *c2;
	*c2 = tmp;
}

void	ft_sort(char *str) /// a b c
{
	int i = 0;
	int j;
	while (str[i])
	{
		j = i + 1;
		while (str[j])
		{
			if (str[i] > str[j])
				ft_swap(&str[i], &str[j]);
			j++;
		}
		i++;
	}
}

void	permutation(char *str, int start, int end)
{
	int i = start;
	printf("start = %d\n", start);
	printf("end = %d\n", end);
	while (i < end)
	{
		ft_sort(&str[start]);
		i++;
	}
	puts(str);
}

int main (int ac , char **av)
{
	if (ac != 2)
		return (puts("invalid input"), 0);
	int len = ft_strlen(av[1]);
	printf("len = %d\n", len);
	char *str = malloc (len * sizeof(char));
	strcpy(str, av[1]);
	permutation(str, 0, len - 1);
}