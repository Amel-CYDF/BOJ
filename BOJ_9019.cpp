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

int n,m;
pii par[1'00'10];
char ans[]="DSLR";
queue<int> bfs;

int amel(int p,int q)
{
	switch(q)
	{
		case 0: return (p<<1)%1'00'00;
		case 1: return (p+9999)%1'00'00;
		case 2: return p%1000*10+p/1000;
		case 3: return p/10+(p%10)*1000;
	}
}

void Solve()
{
	cin>>n>>m;
	for(int i=1'00'00; i--; ) par[i]=mp(-1,-1);
	bfs.push(n); par[n]=mp(n,0);
	while(!bfs.empty())
	{
		auto t=bfs.front(); bfs.pop();
		for(int i=4; i--;)
		{
			int j=amel(t,i);
			if(!~par[j].ff) par[j]=mp(t,i), bfs.push(j);
		}
	}
	string dap;
	for(int i=m; i!=n; i=par[i].ff)
		dap+=ans[par[i].ss];
	reverse(dap.begin(),dap.end());
	cout<<dap<<'\n';
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
