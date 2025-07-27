#include <string.h>
#include <stdio.h>


int check_str(char *str, int start, int end)
{
	int left = start;
	int right = end;
	while (left < right)
	{
		if (str[left] != str[right])
			return (1);
		left++;
		right--;
	}
	return (0);
}

char* longestPalindrome(char* s) {
    int len = strlen(s);
	printf("len = %d\n", len);
	int start = 0;
	int end = len - 1;
	printf("end = %d\n", end);
	printf("%c\n", s[end]);
	char *res = strdup("");
	while (end > 0)
	{
		printf("start = %c\t end = %c\n", s[start], s[end]);
		while (start < end)
		{
			if (check_str(s, start, end))
			{
				res = strndup(s + start + 1, end - 1);
				printf("==> start = %c\t end = %c\n", s[start + 1], s[end - 1]);
				return (res);
			}
			start++;
		}
		end--;
	}
	return (res);
}


int main ()
{
	char *Palindrom = longestPalindrome("cbbd");
	printf("palindrom = %s\n", Palindrom);
}