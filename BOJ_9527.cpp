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

int n,m;
ll x,y,ans;

void Solve()
{
	cin>>x>>y; y++;
	for(int i=0; 1ll<<i <=y; i++)
	{
		ll lf=x&(-1ll ^ (1ll<<i)-1), rg=y&(-1ll ^ (1ll<<i)-1);

		if(x>>i & 1ll) ans+= lf-x;
		if(y>>i & 1ll) ans+= y-rg;
		ans+=((rg>>i+1)-(lf>>i+1))*(1ll<<i);
	}
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

