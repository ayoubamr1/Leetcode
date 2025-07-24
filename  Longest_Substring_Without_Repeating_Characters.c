#include <stdio.h>
#include <string.h>



// int	is_unique(char *str, int start, int end)
// {
// 	int array[128] = {0};
// 	int i = start;
// 	while (i < end)
// 	{
// 		if (array[(int)str[i]])
// 			return (0);
// 		array[(int)str[i]] = 1;
// 		i++;
// 	}
// 	return (1);
// }

// int lengthOfLongestSubstring(char* s) {
// 	int start = 0;
//     int end;
//     int Maxlen = 1;
// 	int n = strlen(s);
// 	printf("n = %d\n", n);
// 	int len = 0;
// 	if (!n)
// 		Maxlen = n;
//     while (start < n)
//     {
//         end = start + 1;
//         while (end <= n)
//         {
//             if (is_unique(s, start, end))
// 				len = end - start;
// 			if (len > Maxlen)
// 				Maxlen = len;
// 			end++;
//         }
//         start++;
//     }
// 	return (Maxlen);
// }


// =======> code optimizer

 
#include <string.h>

int lengthOfLongestSubstring(char* s) {
    int map[128] = {0};
    int left = 0, right = 0;
    int maxlen = 0;
	while (s[right]) {
        char c = s[right];
		// printf("char c = %c\n", c);
        map[(int)c]++;
		// printf("map[(int)%c] = %d\n", c,map[(int)c]);

        while (map[(int)c] > 1) {
            // printf("Duplicate found: '%c' appears %d times\n", c, map[(int)c]);
			map[(int)s[left]]--;
        	// printf("Removing '%c' at s[%d]\n", s[left], left);
            left++;
        }

        int windowlen = right - left + 1;
		// printf("windowlen = %d in loop %d\n", windowlen, right);
        if (windowlen > maxlen)
            maxlen = windowlen;

        right++;
    }

    return maxlen;
}



int main ()
{
	int len = lengthOfLongestSubstring(" ");
	printf("[%d]\n", len);
}