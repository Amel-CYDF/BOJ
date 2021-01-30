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

int n,m;
vvi ed;
ll re[2010]={1};
vpii b;

bool amel(int p,int q)
{
	ed[p].pb(q); ed[q].pb(p);
	queue<int> bfs;
	vi vis(n,0);
	bfs.push(0); vis.front()=1;
	while(!bfs.empty())
	{
		auto t=bfs.front(); bfs.pop();
		for(auto &i:ed[t])
			if(!vis[i]) vis[i]=1, bfs.push(i);
	}
	if(vis.back()) ed[p].pop_back(), ed[q].pop_back();
	return vis.back();
}

void Solve()
{
	cin>>n>>m;
	ed.resize(n);
	for(int i=1;i<m;i++) re[i]=re[i-1]*3%MOD;
	for(int i,j,k=0;k<m;k++)
	{
		cin>>i>>j;
		b.pb(mp(i,j));
	}
	ll ans=0;
	for(int i=m;i--;)
		if(amel(b[i].ff,b[i].ss)) ans=(ans+re[i])%MOD;
	cout<<ans;
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
