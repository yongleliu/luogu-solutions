#include<bits/stdc++.h>
using namespace std;
const int N=1005;
int n,beginlevel,maxlevel,a[N],dp[N][N];//dp[i][j]��i�׸��ܷ񵽴�j���� 
int main()
{
	scanf("%d%d%d",&n,&beginlevel,&maxlevel);
	dp[0][beginlevel]=1;//��ʼ״̬����0�׸裬�տ�ʼ����beginlevel 
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;++i)
		for(int j=0;j<=maxlevel;++j)//��1~n�׸裬ÿ��ѭ��һ������ 
		{
			if(dp[i-1][j]&&a[i]+j<=maxlevel)//����i-1�׸��ܵ���j��������i�׸�ı�������ӵ�ǰ����С�����ֵ 
				dp[i][a[i]+j]=1; 
			if(dp[i-1][j]&&j-a[i]>=0)//����i-1�׸��ܵ���j��������ǰ��������i�׸�ı������ С����Сֵ 
				dp[i][j-a[i]]=1;
		}
	for(int i=maxlevel;i>=0;--i)
		if(dp[n][i])
		{
			printf("%d\n",i);
			return 0;
		}
	printf("-1\n");
	return 0;
}
