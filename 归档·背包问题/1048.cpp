#include<bits/stdc++.h>
using namespace std;
const int N=1005;
int total,m,val[N],t[N],dp[N][N];
int main()
{
	cin>>total>>m;//total������������m��������Ʒ���� 
	for(int i=1;i<=m;++i)
		cin>>t[i]>>val[i];//t������Ʒ������val������Ʒ��ֵ 
	for(int i=1;i<=m;++i)
		for(int j=0;j<=total;++j)
			if(j>=t[i])
				dp[i][j]=max(dp[i-1][j],dp[i-1][j-t[i]]+val[i]);
			else
				dp[i][j]=dp[i-1][j];
	cout<<dp[m][total]<<endl;
	return 0;
}
