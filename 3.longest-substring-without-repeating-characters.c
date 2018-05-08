int lengthOfLongestSubstring(char* s) {
	int i,j,k = 0;
	int len_i, len = 0;
	int flag = 0;
	len = 1;
	while ( s[i] != 0 )
	{
		printf("while 1\n");
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
			printf("while 2\n");
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
