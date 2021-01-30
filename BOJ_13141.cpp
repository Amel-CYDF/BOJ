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

int n,m,a[210];
vvpii ed;

void amel(int p)
{
	memset(a,0x77,sizeof(a));
	a[p]=0;
	priority_queue<pii> dij;
	dij.push(mp(0,p));
	while(!dij.empty())
	{
		auto t=dij.top(); dij.pop();
		if(a[t.ss]!=-t.ff) continue;
		for(auto &i: ed[t.ss])
			if(a[i.ff] > i.ss-t.ff)
				a[i.ff]=i.ss-t.ff, dij.push(mp(-a[i.ff],i.ff));
	}
}

void Solve()
{
	cin>>n>>m;
	ed.resize(n+1);
	for(int i,j,k;m--;)
		cin>>i>>j>>k,ed[i].pb(mp(j,k)),ed[j].pb(mp(i,k));
	m=INT_MAX;
	for(int i=1;i<=n;i++)
	{
		amel(i);
		int t=0;
		for(int j=1;j<=n;j++)
			for(auto &k: ed[j])
				t=max(t, 2*max(a[j],a[k.ff])+k.ss-abs(a[j]-a[k.ff]));
		m=min(m,t);
	}
	cout<<(m>>1)<<'.'<<(m&1?5:0);
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
