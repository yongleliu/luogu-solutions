#include<bits/stdc++.h>
using namespace std;
const int N=1005;
int n,num[N][N],dp[N][N],ans;//dp[i][j]��ʾ�ӵ�1�е�1�е���i�е�j�е�����ۼӺ� 
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=i;++j)
			scanf("%d",&num[i][j]);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=i;++j)
			dp[i][j]=max(dp[i-1][j],dp[i-1][j-1])+num[i][j];
	for(int i=1;i<=n;++i)
		ans=max(ans,dp[n][i]);
	printf("%d\n",ans);
	return 0;
}
