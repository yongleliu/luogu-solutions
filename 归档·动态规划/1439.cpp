#include<bits/stdc++.h>
using namespace std;
const int N=1005;
int n,a[N],b[N],dp[N][N];//dp[i][j]，a字符串前i个长度和b字符串前j个长度的最长公共子串长度 
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;++i)
		scanf("%d",&b[i]);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			if(a[i]!=b[j])
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			else
				dp[i][j]=dp[i-1][j-1]+1;
	printf("%d\n",dp[n][n]);
	return 0;
}
