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

int n,m,a[810];
vvpii ed;

void amel(int p)
{
	memset(a,0x77,sizeof(a));
	priority_queue<pii> dij;
	dij.push(mp(0,p)); a[p]=0;
	while(!dij.empty())
	{
		auto t=dij.top(); dij.pop();
		if(-t.ff!=a[t.ss]) continue;
		for(auto &i: ed[t.ss])
			if(a[i.ff]>-t.ff+i.ss)
				a[i.ff]=-t.ff+i.ss, dij.push(mp(-a[i.ff],i.ff));
	}
}

void Solve()
{
	cin>>n>>m;
	ed.resize(n+1);
	for(int i,j,k; m--; )
	{
		cin>>i>>j>>k;
		ed[i].pb(mp(j,k));
		ed[j].pb(mp(i,k));
	}
	int x,y; cin>>x>>y;
	int p=0,q=0;
	amel(1);
	if(a[x] < 1<<30) p+=a[x];
	else p=-1;
	if(a[y] < 1<<30) q+=a[y];
	else q=-1;
	amel(x);
	if(~p && a[y] < 1<<30) p+=a[y];
	else p=-1;
	if(~q && a[n] < 1<<30) q+=a[n];
	else q=-1;
	amel(y);
	if(~p && a[n] < 1<<30) p+=a[n];
	else p=-1;
	if(~q && a[x] < 1<<30) q+=a[x];
	else q=-1;
	if(!~p) cout<<(~q ? q : -1);
	else cout<<(~q ? min(p,q): p);
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
