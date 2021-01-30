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
#define MOD 1'000'000'007

int n,m,a[100'010];
vvpii ed;
pii par[20][100'010];

void dfs(int p,int pp)
{
	for(auto &i: ed[p])
		if(i.ff!=pp) par[0][i.ff]=mp(p,i.ss),dfs(i.ff,p);
}

void Solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	ed.resize(n+1);
	for(int i,j,k,r=n-1;r--;)
		cin>>i>>j>>k,ed[i].pb(mp(j,k)),ed[j].pb(mp(i,k));
	dfs(1,1);
	par[0][1]=mp(1,0);
	for(int i=1;i<20;i++)
		for(int j=1;j<=n;j++)
		{
			auto t=par[i-1][j];
			par[i][j]=mp(par[i-1][t.ff].ff, par[i-1][t.ff].ss + t.ss);
		}
	for(int i=1;i<=n;i++)
	{
		int t=i, r=a[i], j=0;
		for(; j<20 & par[j][t].ff !=1 && par[j][t].ss <= r; j++) ;
		for(; t!=1; )
		{
			for(; j>=0 && par[j][t].ss > r; j--) ;
			if(!~j) break;
			r-=par[j][t].ss;
			t=par[j][t].ff;
		}
		cout<<t<<'\n';
	}
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
