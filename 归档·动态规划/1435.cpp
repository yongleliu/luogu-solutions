#include<bits/stdc++.h>
using namespace std;
const int N=1005;
int n,dp[N][N];//dp[i][j]��a�ַ���ǰi�����Ⱥ�b�ַ���ǰj�����ȵ�������Ӵ����� 
char c[N],cc[N];
int main()
{
	scanf("%s",c+1);
	int len=strlen(c+1),cnt=0;
	for(int i=len;i>=1;--i)
	{
		++cnt;
		cc[cnt]=c[i];
	}
	for(int i=1;i<=len;++i)
		for(int j=1;j<=len;++j)
			if(c[i]!=cc[j])
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			else
				dp[i][j]=dp[i-1][j-1]+1;
	printf("%d\n",len-dp[len][len]);
	return 0;
}
