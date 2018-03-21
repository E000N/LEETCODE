struct ListNode{
	char val;
	struct ListNode *next;
}
int lengthOfLongestSubstring(char* s) {
	int i,j,k = 0;
	int pos = 0;
	int flag = 0;
	int head = 0;
	int count = 0;
	int max = 0;
	int len = 0;

	while( 0 != s[i] )
	{
		pos = i;
		j = i;
		k = i;
		while ( s[j+1] != 0 && s[j+1] != s[j] )
		{	
			flag = 0;
			k = i;
			while ( k < j+1 )
			{
				if ( s[k] == s[j+1] )
				{
					flag = 1;
					break;
				}
				if ( 1 == flag )
				{
					break;
				}
				k++;
			}
		}
		if ( 
	} 
}
