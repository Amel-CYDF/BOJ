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

struct fenwick2d {
	ll a[5'010][5'010];
	int xsiz, ysiz;

	void init(int p,int q) {
		for(xsiz = 1; xsiz < p; xsiz <<= 1) ;
		for(ysiz = 1; ysiz < q; ysiz <<= 1) ;
	}

	// add p to a[x][y]
	void upd(int x, int y, ll p) {
		for(; x <= xsiz; x += x & -x)
			for(int i=y; i <= ysiz; i += i & -i)
				a[x][i] += p;
	}

	// get rectangular sum from a[1][1] to a[x][y]
	ll sum(int x, int y) {
		ll ret = 0;
		for(; x; x ^= x & -x)
			for(int i=y; i; i ^= i & -i)
				ret += a[x][i];
		return ret;
	}

	// get rectangular sum from a[x1][y1] to a[x2][y2] (x1 < x2, y1 < y2)
	ll sum(int x1, int y1, int x2, int y2) {
		assert(x1 <= x2 && y1 <= y2);
		return sum(x2, y2) - sum(x1 - 1, y2) - sum(x2, y1 - 1) + sum(x1 - 1, y1 - 1);
	}

}a;

int b[1030][1030];

void Solve()
{
	cin>>n>>m;
	a.init(n,n);
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++) cin>>b[i][j], a.upd(i,j,(ll)b[i][j]);
	for(int i,x,y,c,p,q; m--; )
	{
		cin>>i;
		if(i)
		{
			cin>>x>>y>>p>>q;
			cout<<a.sum(x,y,p,q)<<'\n';
		}
		else
		{
			cin>>x>>y>>c;
			a.upd(x,y,(ll)c-b[x][y]);
			b[x][y]=c;
		}
	}
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