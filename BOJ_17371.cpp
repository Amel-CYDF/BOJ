#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
#define pb push_back
#define ff first
#define ss second
#define MOD 1000000007
#define N 100010
#define M 3010
#define SOURCE 51
#define SINK 52

int n,m;
vpii a;
pii ans;
ll dap=1e18;

void Solve()
{
    cin>>n;
    a.resize(n);
    for(auto &i:a) cin>>i.ff>>i.ss;
    for(auto i:a)
    {
        ll tmp=-1;
        for(auto j:a)
        {
            tmp=max(tmp, (ll)(i.ff-j.ff)*(i.ff-j.ff)+(ll)(i.ss-j.ss)*(i.ss-j.ss));
        }
        if(tmp<dap) dap=tmp, ans=i;
    }
    cout<<ans.ff<<' '<<ans.ss;
}

int main(){
   // freopen("input.txt","r",stdin);
//    int tc; cin>>tc; while(tc--)
    Solve();
    return 0;
}
