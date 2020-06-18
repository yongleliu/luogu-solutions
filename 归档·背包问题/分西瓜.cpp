#include<bits/stdc++.h>
using namespace std;
const int N=10005,M=25;
int n,a[M],val[M],dp[N],tot,totalweight;
int main()
{
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
		val[i]=a[i];
		tot+=a[i];
	}
	totalweight=tot;
	tot/=2;
	for(int i=1;i<=n;++i)
		for(int j=tot;j>=a[i];--j)
			dp[j]=max(dp[j],dp[j-a[i]]+val[i]);
	cout<<totalweight-dp[tot]*2<<endl;
	return 0;
}
/*
5
5 8 13 27 14
output:3
*/
