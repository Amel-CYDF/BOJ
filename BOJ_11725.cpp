#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<vpii> vvpii;
typedef vector<vpll> vvpll;
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define MOD 998244353

int n,m,par[1'00'010];
vvi ed;

void dfs(int p)
{
	for(auto &i: ed[p])
		if(!par[i])
			par[i]=p, dfs(i);
}

void Solve()
{
	cin>>n;
	ed.resize(n+1);
	for(int i,j,k=n; k--; ) cin>>i>>j, ed[i].pb(j), ed[j].pb(i);
	dfs(1);
	for(int i=2; i<=n; i++) cout<<par[i]<<'\n';
}

void Init(bool isLocal){ if(isLocal) freopen("input.txt","r",stdin);
	ios::sync_with_stdio(false); cin.tie(NULL);
}
int main(){ Init(01);
//	int tc; cin>>tc; for(int i=1;i<=tc;i++)
//	cout<<"Case #"<<i<<'\n',
	Solve();
	return 0;
}
