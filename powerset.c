#include <stdlib.h>
#include <string.h>
#include <unistd.h>


void backtrack_powerset(int *set, int size, int target, int index, int *power_set, int size_power_set)
{
	
}









int main (int ac, char **av)
{
	int *set;
	int *power_set;
	int size;
	int target;
	int i;

	if (ac < 3)
		return (1);
	target = atoi(av[1]);
	size = ac - 2;
	set = malloc(size * sizeof(int));
	if (!set)
		return (1);
	power_set = malloc(size * sizeof(int));
	if (!power_set)
		return (1);
	i = -1;
	while (++i < size)
		set[i] = atoi(av[i + 2]);
	backtrack_powerset(set, size, target, 0, power_set, 0);
}	