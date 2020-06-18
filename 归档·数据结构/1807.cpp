#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>

using namespace std;

const int N=1505;

struct node
{
    int next,len;
}p;

vector <node> v[N];
queue <int> q;

int n,m,dp[N];
int indegree[N],outdegree[N];

int t;

void Tsort()
{
    for(int i=1;i<=n;++i)
        if(!indegree[i])
            q.push(i);

    while(!q.empty())
    {
        t=q.front();
        q.pop();

        for(int i=0;i<v[t].size();++i)
        {
            int nextnum=v[t][i].next;
            int nextlen=v[t][i].len;

            --indegree[nextnum];
            dp[nextnum]=max(dp[nextnum],dp[t]+nextlen);
            if(!indegree[nextnum])
                q.push(nextnum);
        }
    }
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;++i)
    {
        int x,y,len;
        scanf("%d%d%d",&x,&y,&len);
        p.next=y;
        p.len=len;
        v[x].push_back(p);
        ++outdegree[x];
        ++indegree[y];
    }

    for(int i=1;i<=n;++i)
        dp[i]=-(1<<29);
    dp[1]=0;

    Tsort();

    if(dp[n]!=-(1<<29))
        printf("%d\n",dp[n]);
    else
        printf("-1\n");
    return 0;
}