#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 230
#define MOD 1001
#define SOURCE 0
#define SINK 222

int n,m,a[N][N],now[N][N],pre[N],vis[N],dis[N],ans;
int cost[N][N];
list<int> ed[N];

int main(){
   // freopen("input.txt","r",stdin);
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",a[SOURCE]+i),ed[SOURCE].push_back(i),ed[i].push_back(SOURCE);
    for(int i=101;i<101+m;i++) scanf("%d",a[i]+SINK),ed[SINK].push_back(i),ed[i].push_back(SINK);
    for(int i=1;i<=n;i++)
        for(int j=101;j<101+m;j++) a[i][j]=INT_MAX;
    for(int j=101;j<101+m;j++)
        for(int i=1;i<=n;i++) scanf("%d",cost[i]+j),cost[j][i]=-cost[i][j];
    for(int i=1;i<=n;i++)
        for(int j=101;j<101+m;j++) ed[i].push_back(j),ed[j].push_back(i);

    while(1)
    {
        memset(vis,0,sizeof(vis));
        memset(pre,0,sizeof(pre));
        memset(dis,127,sizeof(dis));
        queue<int> flow;
        flow.push(SOURCE); dis[SOURCE]=0;
        while(!flow.empty())
        {
            int p=flow.front(); flow.pop(); vis[p]=0;
            for(int i:ed[p])
                if(now[p][i]<a[p][i]&&dis[i]>dis[p]+cost[p][i])
                {
                    dis[i]=dis[p]+cost[p][i];
                    pre[i]=p;
                    if(!vis[i]) flow.push(i),vis[i]=1;
                }
        }
        if(dis[SINK]>1<<30) break;
        int minflow=INT_MAX;
        for(int pos=SINK;pos!=SOURCE;pos=pre[pos])
            minflow=min(minflow,a[pre[pos]][pos]-now[pre[pos]][pos]);
        for(int pos=SINK;pos!=SOURCE;pos=pre[pos])
            now[pre[pos]][pos]+=minflow,
            now[pos][pre[pos]]-=minflow;
    }
    for(int i=1;i<=n;i++)
        for(int j=101;j<101+m;j++) ans+=cost[i][j]*now[i][j];
    printf("%d",ans);
    return 0;
}
