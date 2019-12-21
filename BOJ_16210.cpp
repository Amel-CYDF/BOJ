#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,int> pii;
#define pb push_back
#define ff first
#define ss second
#define N 500010
#define M 12
#define MOD 998244853

int n;
ll ans[N];
pii a[N],b[N];

void amel(pii p[])
{
    sort(p+1,p+n+1);
    ll lf=0,rg=0;
    for(int i=1;i<=n;i++) rg+=p[i].ff;
    for(int i=1;i<=n;i++)
        rg-=p[i].ff,
        ans[p[i].ss]+=rg-lf+p[i].ff*((i<<1)-1-n),
        lf+=p[i].ff;
}

int main(){
 //   freopen("input.txt","r",stdin);
    cin>>n;
    for(int i=1;i<=n;i++) a[i].ss=b[i].ss=i,cin>>a[i].ff>>b[i].ff;
    amel(a); amel(b);
    printf("%d",min_element(ans+1,ans+n+1)-ans);
    return 0;
}
