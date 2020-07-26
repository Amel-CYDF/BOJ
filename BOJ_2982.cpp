#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define pb push_back
#define ff first
#define ss second
#define MOD 1000
#define N 100010
#define M 3010

int n,m,s,e,v,k,a[1010][1010],b[1010][1010],c[1010],d[1010];
list<pii> ed[1010];
priority_queue<pii> r;

int main(){
 //   freopen("input.txt","r",stdin);
    cin>>n>>m>>s>>e>>v>>k;
    for(int i=0;i<k;i++) scanf("%d",c+i);
    for(int x,y,z;m--;)
    {
        cin>>x>>y>>z;
        ed[x].pb({y,z}); ed[y].pb({x,z});
    }
    for(int i=1,x,y,sum=0;i<k;i++)
    {
        x=c[i-1]; y=c[i];
        for(auto j:ed[x])
            if(j.ff==y)
            {
                a[x][y]=a[y][x]=sum;
                b[x][y]=b[y][x]=sum+j.ss;
                sum+=j.ss;
                break;
            }
    }
    r.push({-v,s});
    while(!r.empty())
    {
        auto t=r.top(); r.pop();
        if(d[t.ss]) continue;
        d[t.ss]=1;
        t.ff=-t.ff;
        if(t.ss==e) {printf("%d",t.ff-v); break;}
        for(auto i:ed[t.ss])
        {
            int f=t.ff+i.ss;
            if(a[t.ss][i.ff]<=t.ff&&t.ff<b[t.ss][i.ff]) f=b[t.ss][i.ff]+i.ss;
            r.push({-f,i.ff});
        }
    }
    return 0;
}