#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define MOD 1000
#define N 100010
#define M 3010

int n,m;
pii a[N],b[N];
multiset<pii> c;
ll ans;

bool cmp(pii lhs,pii rhs)
{
    return lhs.ss>rhs.ss;
}

int main(){
 //   freopen("input.txt","r",stdin);
    cin>>n>>m;
    for(int i=0;i<n;i++) scanf("%d %d",&a[i].ff,&a[i].ss);
    for(int i=0;i<m;i++) scanf("%d %d",&b[i].ff,&b[i].ss);
    sort(a,a+n,cmp); sort(b,b+m,cmp);
    for(int i=0,j=0;i<n;i++)
    {
        while(j<m&&b[j].ss>=a[i].ss) c.insert(b[j++]);
        auto t=c.lower_bound(a[i]);
        if(t==c.end()) {printf("-1"); return 0;}
        ans+=(ll)t->ff; c.erase(t);
    }
    cout<<ans;
    return 0;
}
