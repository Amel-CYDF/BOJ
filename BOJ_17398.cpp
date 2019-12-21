#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define N 100010
#define M 25
#define MOD 10007

int n,m,k,par[N],siz[N],a[N],c[N];
ll ans;
pii b[N];

int parfind(int p)
{
    if(p==par[p]) return p;
    return par[p]=parfind(par[p]);
}

ll uni(int p,int q)
{
    p=parfind(p); q=parfind(q);
    if(p==q) return 0;
    ll ret=(ll)siz[p]*siz[q];
    par[q]=p; siz[p]+=siz[q];
    return ret;
}

int main(){
   // freopen("input.txt","r",stdin);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++) cin>>b[i].first>>b[i].second;
    for(int i=0;i<k;i++) cin>>a[i],c[a[i]]=1;
    for(int i=1;i<=n;i++) par[i]=i,siz[i]=1;
    for(int i=1;i<=m;i++) if(!c[i]) uni(b[i].first,b[i].second);
    for(int i=0;i<k;i++) ans+=uni(b[a[i]].first,b[a[i]].second);
    cout<<ans;
    return 0;
}
