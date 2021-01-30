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

int n,m,a[1'00'010],vis[1'00'010],b[1'00'010];

void dfs(int p)
{
	if(b[p])
	{
		for(int i=a[p]; i!=p; i=a[i]) m--;
		m--;
		return;
	}
	if(vis[p]) return;
	vis[p]=b[p]=1;
	dfs(a[p]);
	b[p]=0;
}

void Solve()
{
	cin>>n; m=n;
	for(int i=1; i<=n; i++) cin>>a[i];
	memset(vis,0,sizeof(vis));
	for(int i=1; i<=n; i++)
		dfs(i);
	cout<<m<<'\n';
}

void Init(bool isLocal){ if(isLocal) freopen("input.txt","r",stdin);
	ios::sync_with_stdio(false); cin.tie(NULL);
}
int main(){ Init(01);
	int tc; cin>>tc; for(int i=1;i<=tc;i++)
//	cout<<"Case #"<<i<<'\n',
	Solve();
	return 0;
}
