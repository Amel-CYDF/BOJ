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
ll a,b;
vector<vi> ed;

void dfs(int par, int lev, int p)
{
    if(ed[p].size()>=3)
    {
        ll tmp=ed[p].size();
        a+=tmp*(tmp-1)*(tmp-2)/6;
    }

    if(lev>=3) b++;

    if(ed[p].size()>=3)
    {
        for(auto i:ed[p])
            if(i!=par&&ed[i].size()>=2)
            {
                b+= (ll)(ed[p].size()-2) * (ed[i].size()-1);
            }
    }

    lev++;
    for(auto i:ed[p])
        if(i!=par) dfs(p, lev, i);
}

void Solve()
{
    cin>>n;
    ed.resize(n);
    for(int i=n-1,j,k;i--;)
    {
        cin>>j>>k;
        j--; k--;
        ed[j].pb(k);
        ed[k].pb(j);
    }
    for(int i=n;i--;) if(ed[i].size()==1) {dfs(-1, 0, i); break;}
    if(b > 3*a) cout<<"D";
    else if(b < 3*a) cout<<"G";
    else cout<<"DUDUDUNGA";
}

int main(){
  //  freopen("input.txt","r",stdin);
//    int tc; cin>>tc; while(tc--)
    Solve();
    return 0;
}
