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

int n,m,a[10'010],b[10'010];
vvi ed;

int dfs(int p,int pp)
{
	int ret=a[p]=++m;
	for(auto &i:ed[p])
	{
		if(a[i]) ret=min(ret,a[i]);
		else
		{
			int t=dfs(i,p);
			if(p==pp) {b[p]++; continue;}
			b[p] |= a[p]<=t;
			ret=min(ret,t);
		}
	}
	if(p==pp) b[p]=b[p]>1;
	return ret;
}

void Solve()
{
	cin>>n>>m;
	ed.resize(n+1);
	for(int i,j;m--;)
		cin>>i>>j, ed[i].pb(j), ed[j].pb(i);
	m=0;
	for(int i=1;i<=n;i++)
		if(!a[i]) dfs(i,i);
	m=0;
	for(int i=1;i<=n;i++) m+=b[i];
	cout<<m<<'\n';
	for(int i=1;i<=n;i++) if(b[i]) cout<<i<<' ';
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
