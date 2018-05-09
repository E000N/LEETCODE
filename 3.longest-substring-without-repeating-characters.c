int lengthOfLongestSubstring(char* s) {
	int i = 0,j = 0,k = 0;
	int len_i = 0, len = 0;
	int flag = 0;
	len = 0;
	while ( s[i] != 0 )
	{
		j = i;
		k = i;
		len_i = 0;
		flag = 0;
		if ( 0 == s[i+1] )
		{
			if ( 0 == len )
			{
				len  = 1;
			}
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
			printf("temp%d", len_i);
			if  ( len_i > len )
			{
				len = len_i;
			}
			printf("max %d", len);
		}
		i++;
	}
	printf("final %d", len);
	return len; 
}
