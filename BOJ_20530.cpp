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

int n,m,par[2'00'010], a[2'00'010];
vvi ed;
vi c;

bool dfs(int p,int q)
{
	if(par[p])
	{
		vi x,y;
		for(int i=p; i!=1; i=par[i]) x.pb(i);
		for(int i=q; i!=1; i=par[i]) y.pb(i);
		x.pb(1); y.pb(1);
		for(; x.size()>1&&y.size()>1; )
			if(x[x.size()-2]==y[y.size()-2]) x.pop_back(),y.pop_back();
		c=x; for(auto &i: y) c.pb(i);
		c.pop_back();
		for(auto &i: c) a[i]=1;
		return true;
	}
	par[p]=q;
	for(auto &i: ed[p])
		if(i!=q && dfs(i,p)) return true;
	return false;
}

void dfss(int p,int r)
{
	if(par[p]) return;
	par[p]=r;
	for(auto &i: ed[p]) dfss(i,r);
}

void Solve()
{
	cin>>n>>m;
	ed.resize(n+1);
	for(int i,j,k=n; k--;)
		cin>>i>>j, ed[i].pb(j), ed[j].pb(i);
	dfs(1,1);
	memset(par,0,sizeof(par));
	for(auto &i: c) par[i]=i;
	for(auto &i: c) par[i]=0, dfss(i,i);
//	for(int i=1; i<=n; i++) cout<<par[i]<<' ';
//	cout<<endl;
	for(int ii=m,i,j; ii--;)
	{
		cin>>i>>j;
		cout<<( par[i]==par[j] ? 1 : 2)<<'\n';
	}
}

void Init(bool isLocal){ if(isLocal) freopen("input.txt","r",stdin);
	ios::sync_with_stdio(false); cin.tie(NULL);
}
int main(){ Init(0);
//	int tc; cin>>tc; for(int i=1;i<=tc;i++)
//	cout<<"Case #"<<i<<'\n',
	Solve();
	return 0;
}
