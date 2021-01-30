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

int n,m,a[510][510],k;
pii ans(INT_MAX,0);

void upd(pii q)
{
	if(ans.ff > q.ff) ans = q;
	else if(ans.ff == q.ff && ans.ss < q.ss) ans = q;
}

void Solve()
{
	cin>>n>>m>>k;
	for(int i = n; i--; )
		for(int j = m; j--; ) cin>>a[i][j];
	for(int i = 0; i <= 256; i++)
	{
		int t = k, u=0;
		for(int j = n; j--; )
			for(int r = m; r--; )
				t+=a[j][r] - i;
		if(t < 0) continue;
		for(int j = n; j--; )
			for(int r = m; r--; )
			{
				if(a[j][r] > i) u += 2 * (a[j][r] - i);
				else u += i - a[j][r];
			}
		upd(mp(u, i));
	}
	cout<<ans.ff<<' '<<ans.ss;
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
