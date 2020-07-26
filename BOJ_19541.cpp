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
vector<vi> moim;
vi a,b,c;

void Solve()
{
    cin>>n>>m;
    moim.resize(m);
    a.resize(n);
    b.resize(n);
    c.resize(n);
    for(int i=m,j,k;i--;)
    {
        cin>>j;
        while(j--) cin>>k, moim[i].pb(k-1);
    }
    for(auto &i:a) cin>>i;
    for(int i=n;i--;) b[i]=!a[i];
    for(auto i:moim)
    {
        bool flag=false;
        for(auto j:i) if(b[j]) {flag=true; break;}
        if(flag)
            for(auto j:i) b[j]=1;
    }
    for(int i=n;i--;) c[i]=b[i]=!b[i];
    reverse(moim.begin(), moim.end());
    for(auto i:moim)
    {
        bool flag=false;
        for(auto j:i) if(b[j]) {flag=true; break;}
        if(flag)
            for(auto j:i) b[j]=1;
    }
    for(int i=n;i--;) if(a[i]!=b[i]) {cout<<"NO"; return;}
    cout<<"YES\n";
    for(auto i:c) cout<<i<<' ';
}

int main(){
  //  freopen("input.txt","r",stdin);
//    int tc; cin>>tc; while(tc--)
    Solve();
    return 0;
}
