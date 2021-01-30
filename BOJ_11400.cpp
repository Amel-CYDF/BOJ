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
vvi ed;
vpii ans;

int dfs(int p,int pp)
{
	int ret=a[p]=++m;
	for(auto &i:ed[p])
		if(i!=pp)
		{
			if(a[i]) ret=min(ret,a[i]);
			else
			{
				int t=dfs(i,p);
				if(a[p]<t) ans.pb(mp(min(p,i),max(p,i)));
				else ret=min(ret,t);
			}
		}
	return ret;
}

void Solve()
{
	cin>>n>>m;
	ed.resize(n+1);
	for(int i,j;m--;)
		cin>>i>>j, ed[i].pb(j), ed[j].pb(i);
	m=0;
	dfs(1,1);
	sort(ans.begin(),ans.end());
	cout<<ans.size()<<'\n';
	for(auto &i:ans) cout<<i.ff<<' '<<i.ss<<'\n';
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
