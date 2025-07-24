#include <stdio.h>
#include <string.h>



int	is_unique(char *str, int start, int end)
{
	int array[128] = {0};
	int i = start;
	while (i < end)
	{
		if (array[(int)str[i]])
			return (0);
		array[(int)str[i]] = 1;
		i++;
	}
	return (1);
}

int lengthOfLongestSubstring(char* s) {
	int start = 0;
    int end;
    int Maxlen = 1;
	int n = strlen(s);
	printf("n = %d\n", n);
	int len = 0;
	if (!n)
		Maxlen = n;
    while (start < n)
    {
        end = start + 1;
        while (end <= n)
        {
            if (is_unique(s, start, end)) // p w w k e w
										  //  st end
				len = end - start;
			if (len > Maxlen)
				Maxlen = len;
			end++;
        }
        start++;
    }
	return (Maxlen);
}


int main ()
{
	int len = lengthOfLongestSubstring("ay");
	printf("[%d]\n", len);
}