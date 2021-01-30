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

void Solve()
{
	for(; ;)
	{
		cin>>n;
		if(!n) return;
		vpii b;
		ll ans=0;
		for(int i=0,j;i<n;i++)
		{
			cin>>j;
			int t=i;
			for(; !b.empty() && b.back().ff>j; b.pop_back())
				t=b.back().ss,
				ans=max(ans, (ll)b.back().ff * (i-b.back().ss));
			if(b.empty() || b.back().ff < j) b.pb(mp(j,t));
		}
		for(auto &i: b) ans=max(ans, (ll)i.ff * (n-i.ss));
		cout<<ans<<'\n';
	}
}

void Init(bool isLocal=0){ if(isLocal) freopen("input.txt","r",stdin);
	ios::sync_with_stdio(false); cin.tie(NULL);
}
int main(){ Init(1);
//	int tc; cin>>tc; for(int i=1;i<=tc;i++)
//	cout<<"Case #"<<i<<'\n',
	Solve();
	return 0;
}
