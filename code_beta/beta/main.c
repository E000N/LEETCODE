#include <stdio.h>
#include <stdlib.h>

int lengthOfLongestSubstring(char* s) {
	int i,j,k = 0;
	int len_i, len = 0;
	int flag = 0;
	len = 1;
	while ( s[i] != 0 )
	{
		j = i;
		k = i;
		len_i = 0;
		flag = 0;
		if ( 0 == s[i+1] )
		{
			break;
		}
		while ( 0 == flag )
		{
			if ( 0 == s[j+1] )
			{
				flag = 1;
				break;
			}
			for(k=i;k<=j;k++)
			{
				if ( s[j+1] == s[k] )
				{
					flag = 1;
					j--;
					break;
				}
			}
			j++;
		}
		if ( 1 == flag )
		{
			len_i = j - i + 1;
			if  ( len_i > len )
			{
				len = len_i;
			}
		}
		i = j;
		i++;
	}
	return len;
}


int main()
{
    int ans = 0;
    int i = 0;

    char a[10] = "bbbbb";

    ans = lengthOfLongestSubstring(a);

    printf("ans:%d", ans);

    return 0;
}

