#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define pb push_back
#define ff first
#define ss second
#define MOD 600921647
#define N 100000
#define M 3010

int n,d[N+10];
ll m;

struct line
{
    ll a,b,nxp,nxc;
    bool operator<(line rhs)const
    {
        return a>rhs.a;
    }
};

set<line> a;

ll dap()
{
    if(a.empty()) return 0;
    for(;;)
    {
        auto i=a.begin();
        if(i->nxp > m * i->nxc) return i->a * m + i->b;
        a.erase(i);
    }
}

bool lfcmp(line lhs,line it)
{
    return (it.b-lhs.b)*lhs.nxc > lhs.nxp*(lhs.a-it.a);
}

bool rgcmp(line lhs,line it)
{
    return (lhs.b-it.b)*lhs.nxc >= lhs.nxp*(it.a-lhs.a);
}

void pushline(ll p,ll q)
{
    line nw={p,q,10000000000010,1};

    if(a.empty()) {a.insert(nw); return;}
    if(a.begin()->a <= p) return;

    auto mid = a.lower_bound(nw);
    auto lf = lower_bound(a.begin(),mid,nw,lfcmp);
    auto rg = lower_bound(mid,a.end(),nw,rgcmp);
    
    if(lf==mid) return;
    a.erase(++lf,rg);
    mid = a.lower_bound(nw);
    if(mid!=a.end())
    {
        nw.nxp = mid->b - q;
        nw.nxc = p - mid->a;
    }
    --mid;
    line tmp=*mid;
    tmp.nxp = q - tmp.b;
    tmp.nxc = tmp.a - p;
    a.erase(mid); a.insert(tmp);
    a.insert(nw);
}

int main(){
    freopen("input.txt","r",stdin);
    /*
int tc; cin>>tc;
while(tc--)
{//*/

    cin>>n;
    for(int i=0;i<n-1;i++) scanf("%d",d+i);
    for(int i=0,j,k;i<n-1;i++)
    {
        scanf("%d %d",&j,&k);
        pushline(k, dap()+j- m*k);
        m+=d[i];
    }
    cout<<dap();

    /*
}//*/
    return 0;
}
