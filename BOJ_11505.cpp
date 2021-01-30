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

int n,m,k;

struct segtree {
	ll a[3'000'010];
	int siz;

	void init(int p, vector<ll> &src) {
		// Do any initialize on a[] if not using sum;
		for(int i=3'000'010;i--;) a[i]=1;
		for(siz = 1; siz < p; siz <<= 1) ;
		for(int i = p; i--; ) a[i | siz] = src[i];
		for(int i = siz; i--; ) a[i] = a[i << 1] * a[i << 1 | 1]%MOD; // +
	}

	// set a[pos] to p
	void upd(int pos, ll p) {
		a[pos |= siz] = p; 						// or += p;
		for(pos >>= 1; pos; pos >>= 1)
			a[pos] = a[pos << 1] * a[pos << 1 | 1]%MOD;	// +
	}

	// get a[lf] + a[lf + 1] + ... + a[rg]
	ll sum(int lf, int rg) {
		ll ret = 1;							// Init
		lf |= siz; rg |= siz;
		while(lf < rg) {
			if(lf & 1) ret *= a[lf++],ret%=MOD; 			// +
			else if(~rg & 1) ret *= a[rg--],ret%=MOD;	// +
			else lf >>= 1, rg >>= 1;
		}
		return ret * a[lf]%MOD; 					// +
	}
}a;


void Solve()
{
	cin>>n>>m>>k;
	vl r;
	for(int i=n,j;i--;) cin>>j,r.pb((ll)j);
	a.init(n,r);
	m+=k;
	for(int w,i,j;m--;)
	{
		cin>>w>>i>>j;
		if(w&1) a.upd(i-1,(ll)j);
		else cout<<a.sum(i-1,j-1)<<'\n';
	}
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
