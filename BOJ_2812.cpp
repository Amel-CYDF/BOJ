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
vector<int> a;

void Solve()
{
    cin>>n>>m;
    int t = n - m;
    for(int i; n--; )
    {
        scanf("%1d",&i);
        while(m&&!a.empty()&&a.back()<i) a.pop_back(), m--;
        a.pb(i);
    }
    a.resize(t);
    for(auto i : a) cout<<i;
}

int main(){
//    freopen("input.txt","r",stdin);
//    int tc; cin>>tc; while(tc--)
    Solve();
    return 0;
}
