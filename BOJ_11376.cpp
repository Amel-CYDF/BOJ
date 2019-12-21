#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1001
#define SOURCE 0
#define SINK 2020

int n,m,a[1<<11][1<<11],now[1<<11][1<<11],ans,lev[1<<11];
list<int> ed[1<<11];

int dfs(int p,int maxflow)
{
    if(p==SINK) return maxflow;
    for(int i:ed[p])
        if(lev[i]==lev[p]+1&&now[p][i]<a[p][i])
        {
            int ret=min(maxflow,dfs(i,min(maxflow,a[p][i]-now[p][i])));
            if(ret>0)
            {
                now[p][i]+=ret; now[i][p]-=ret;
                return ret;
            }
        }
    return 0;
}

int main(){
   // freopen("input.txt","r",stdin);
    scanf("%d %d",&n,&m);
    for(int i=1,s;i<=n;i++)
    {
        scanf("%d",&s);
        for(int j=0,t;j<s;j++)
            scanf("%d",&t),t+=1<<10,
            a[i][t]=1, ed[i].push_back(t),ed[t].push_back(i);
    }
    for(int i=1;i<=n;i++) a[SOURCE][i]=2,ed[SOURCE].push_back(i);
    for(int i=(1<<10)+1;i<=(1<<10)+m;i++) a[i][SINK]=1,ed[i].push_back(SINK);
    while(1)
    {
        memset(lev,0,sizeof(lev));
        queue<int> flow;
        flow.push(SOURCE); lev[SOURCE]=1;
        while(!flow.empty())
        {
            int p=flow.front(); flow.pop();
            if(lev[SINK]) break;
            for(int i:ed[p])
                if(!lev[i]&&now[p][i]<a[p][i])
                    lev[i]=lev[p]+1,flow.push(i);
        }
        if(!lev[SINK]) break;
        for(int tmp;tmp=dfs(SOURCE,INT_MAX);ans+=tmp) ;
    }
    printf("%d",ans);
    return 0;
}
