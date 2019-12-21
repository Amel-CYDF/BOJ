#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<long long,int> pli;
#define N 100010

int n,m,go[N],vis[N];
ll ans[N];
list<pli> ed[N];

int main(){
  //  freopen("input.txt","r",stdin);
    memset(ans,127,sizeof(ans));
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++) scanf("%d",go+i);
    go[n-1]=0;
    for(int i=0,s,t,w;i<m;i++)
    {
        scanf("%d %d %d",&s,&t,&w);
        if(!go[s]&&!go[t]) ed[s].push_back({(ll)w,t}),ed[t].push_back({(ll)w,s});
    }
    priority_queue<pli> dij;
    dij.push({0,0}); ans[0]=0;
    while(!dij.empty())
    {
        int p=dij.top().second;
        ll q=dij.top().first*-1; dij.pop();
        if(vis[p]) continue;
        vis[p]=1;
        for(pli i:ed[p])
            if(ans[i.second]>q+i.first)
                ans[i.second]=q+i.first,dij.push({-ans[i.second],i.second});
    }
    if(ans[n-1]>1ll<<35) printf("-1");
    else printf("%lld",ans[n-1]);
    return 0;
}