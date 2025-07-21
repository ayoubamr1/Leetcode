#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
	int i, j;
	i = 0;
	int *res = malloc (2 * sizeof(int));
	while (i < numsSize)
	{
		j = i + 1;
		while (j < numsSize)
		{
			if (nums[i] + nums[j] == target)
			{
				res[0] = i;
				res[1] = j;
				*returnSize = 2;
				return (res);
			}
			j++;
		}
		i++;
	}
	*returnSize = 0;
	return (NULL);
}

/**
int main ()
{
	int arr[] = {5, 9, 7, 0, 6};
	int	returnsize;
	int *res = twoSum(arr, 5, 16, &returnsize);
	int i = 0;
	while (i < 2)
	{
		printf("[%d] -> ", res[i]);
		i++;
	}
}
*/