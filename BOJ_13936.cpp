#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define pb push_back
#define ff first
#define ss second
#define N 100010
#define M 100010
#define MOD 1000000009

int n,m,k,a[N],b[N],c[N],ans=INT_MAX;
list<int> ed[N],rv[N];

void bfs(int p[])
{
    queue<int> v;
    for(int i=1;i<=n;i++) if(!p[i]) v.push(i);
    while(!v.empty())
    {
        int t=v.front(); v.pop();
        if(p==c)
        {
            for(int i:ed[t])
                if(p[i]>>22) p[i]=p[t]+1,v.push(i);
        }
        else
        {
            for(int i:rv[t])
                if(p[i]>>22) p[i]=p[t]+1,v.push(i);
        }
    }
}

int main(){
  //  freopen("input.txt","r",stdin);
    memset(a,1,sizeof(a));
    memset(b,1,sizeof(b));
    memset(c,1,sizeof(c));
    cin>>n>>m>>k;
    c[1]=0;
    for(int i=m,j;i--;) cin>>j,a[j]=0;
    for(int i=k,j;i--;) cin>>j,b[j]=0;
    for(int i=1,j,s;i<=n;i++)
        for(cin>>j;j--;) cin>>s,ed[i].pb(s),rv[s].pb(i);
    bfs(a); bfs(b); bfs(c);
    for(int i=1;i<=n;i++)
        if(!(a[i]>>22||b[i]>>22||c[i]>>22)) ans=min(ans,a[i]+b[i]+c[i]);
    if(ans==INT_MAX) printf("impossible");
    else cout<<ans;
    return 0;
}
