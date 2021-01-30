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

int n,m,k,a[10'010],vis[10'010];
vvi ed;

int dfs(int p)
{
	if(vis[p]) return INT_MAX;
	vis[p]=1;
	int ret=a[p];
	for(auto &i: ed[p])
		ret=min(ret,dfs(i));
	return ret;
}

void Solve()
{
	cin>>n>>m>>k;
	ed.resize(n);
	for(int i=0; i<n; i++) cin>>a[i];
	for(int i,j;m--;)
		cin>>i>>j,i--,j--,ed[i].pb(j),ed[j].pb(i);
	m=0;
	for(int i=n;i--;)
		if(!vis[i]) m+=dfs(i);
	if(m>k) cout<<"Oh no";
	else cout<<m;
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
