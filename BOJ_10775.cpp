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
#define MOD 1'000'000'003

int n,m,par[100'010];

int parfind(int p)
{
	if(par[p]==p) return p;
	return par[p]=parfind(par[p]);
}

void uni(int p,int q)
{
	par[parfind(p)]=parfind(q);
}

void Solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) par[i]=i;
	int ans=0;
	for(int i; m--;)
	{
		cin>>i;
		if(i = parfind(i)) ans++, uni(i, i-1);
		else break;
	}
	cout<<ans;
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

