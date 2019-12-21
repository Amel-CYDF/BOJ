#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,ll> pii;
typedef pair<ll,int> pll;
#define pb push_back
#define ff first
#define ss second
#define MOD 1000000009
#define N 100010
#define M 62510

int n,m,d,e;
list<pii> ed[N];
ll h[N],a[N],b[N],ans=LLONG_MIN;

void dij(int p,ll q[])
{
    bool vis[N]={0};
//    memset(vis,0,sizeof(vis));
    memset(q,-1,sizeof(q));
    priority_queue<pll,vector<pll>,greater<pll> > s;
    s.push({0,p});
    while(!s.empty())
    {
        auto t=s.top(); s.pop();
        if(vis[t.ss]) continue;
        vis[t.ss]=1;
        q[t.ss]=t.ff;
        for(auto i:ed[t.ss])
            if(!vis[i.ff]&&h[t.ss]<h[i.ff]) s.push({t.ff+i.ss,i.ff});
    }
}

int main(){
   // freopen("input.txt","r",stdin);
    cin>>n>>m>>d>>e;
    for(int i=1;i<=n;i++) scanf("%lld",h+i);
    for(int s,t,w;m--;) scanf("%d %d %d",&s,&t,&w),ed[s].pb({t,(ll)w}),ed[t].pb({s,(ll)w});
    dij(1,a); dij(n,b);
    for(int i=2;i<n;i++)
        if(a[i]>0&&b[i]>0) ans=max(ans,h[i]*e-(a[i]+b[i])*d);
    if(ans==LLONG_MIN) cout<<"Impossible";
    else cout<<ans;
    return 0;
}
