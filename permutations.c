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
	// printf("c1 = %c c2 = %c\n", *c1, *c2);
	char tmp;

	tmp = *c1;
	*c1 = *c2;
	*c2 = tmp;
}

void	ft_sort(char *str) /// b c a / a c b / a b c / 
{
	int i = 0;
	int j;
	while (str[i])
	{
		// printf("str = %s\n", str);
		// printf("adress of str = %p value of str = %c\n", str, str[i]);
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
	// printf("i = %d\n", i);
	// printf("start = %d\n", start);
	// printf("start = %d end = %d\n", start, end);
	// printf("str[start] = %c str[i] = %c\n", str[start], str[i]);
	if (start == end)
	{
		puts(str);
		return ;
	}
	// printf("start = %d\n", start);
	// printf("end = %d\n", end);
	while (i < end)
	{
		ft_sort(&str[i]);
		ft_swap(&str[start], &str[i]);
		permutation(str, start + 1, end);
		ft_swap(&str[start], &str[i]);
		// printf("===== str[start] = %c str[i] = %c ======\n", str[start], str[i]);
		i++;
	}
	// puts(str);
}

int	ft_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (i);
}

int main (int ac , char **av)
{
	if (ac != 2)
		return (puts("invalid input"), 0);
	int len = ft_strlen(av[1]);
	// printf("len = %d\n", len);
	char *str = malloc (len + 1 * sizeof(char));
	ft_strcpy(str, av[1]);
	// printf("str = %s\n", str);
	permutation(str, 0, len);
}