/*
 * [5] Longest Palindromic Substring
 *
 * https://leetcode.com/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (25.37%)
 * Total Accepted:    316.1K
 * Total Submissions: 1.2M
 * Testcase Example:  '"babad"'
 *
 * Given a string s, find the longest palindromic substring in s. You may
 * assume that the maximum length of s is 1000.
 * 
 * Example 1:
 * 
 * 
 * Input: "babad"
 * Output: "bab"
 * Note: "aba" is also a valid answer.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "cbbd"
 * Output: "bb"
 * 
 * 
 */
char* longestPalindrome(char* s) {
	int i = 0, pos = 0, j = 0;
	int head = 0, end = 0, len = 0;
	int flag = 0;
	char *ans = (char*)malloc(sizeof(char)*1000);

	while(s[pos] != 0)
	{
		i = pos + 1;
		while(s[i] != 0)
		{
			if ( s[i] == s[pos] )
			{
				flag = 1;
				head = pos;
				end = i;
			}
			i++;
		}
		if ( flag != 0 )
		{
			break;
		}
		pos++;
	}
	printf("%d, %d, %d", head, end, flag);
	j = 0;
	if ( flag != 0 )
	{
		for ( i=head; i<=end; i++ )
		{
			ans[j] = s[i];
			j++;
		}
	}
	else
	{
		ans[0] = s[0];
	}
	printf("ans %s", ans);
	return ans;
}
