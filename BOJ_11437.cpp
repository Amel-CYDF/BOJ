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
#define MOD 1'000'000'003

int n,m;
vvi ed;

const int ln = 20;
int par[100'010][ln],lev[100'010];
//vector<vector<int>> ed;

// ed[i] stores neighbors of node i (ed[][] is vector<vector< >> or 2D array)
void dfs(int p, int pp) {
	lev[p] = lev[pp] + 1;
	par[p][0] = pp;
	for(auto &i : ed[p])
		if(i != pp) dfs(i, p);
}

void init_lca(int rt) {
	dfs(rt, rt);
	par[rt][0] = rt;
	for(int i = 1; i < ln; i++)
		for(int j = 1; j <=n; j++)
			par[j][i] = par[par[j][i - 1]][i - 1];
}

int lca(int p, int q)
{
	if(lev[p] < lev[q]) swap(p, q);
	if(lev[p] > lev[q]) {
		for(int i = ln; i--; )
			if(lev[p] - lev[q] >> i & 1)
				p = par[p][i];
	}
	if(p == q) return p;
	for(int i = ln; i--; )
		if(par[p][i] != par[q][i])
			p = par[p][i],
			q = par[q][i];
	return par[p][0];
}

void Solve()
{
	cin>>n;
	ed.resize(n+1);
	for(int i,j,k=n-1;k--;)
		cin>>i>>j,ed[i].pb(j),ed[j].pb(i);
	init_lca(1);
	cin>>m;
	for(int i,j;m--;)
		cin>>i>>j,cout<<lca(i,j)<<'\n';
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

