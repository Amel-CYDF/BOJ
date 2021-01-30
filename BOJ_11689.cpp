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

ll n,m;
bitset<1'000'010> p;
vi a;

void Solve()
{
	cin>>n;
	a.pb(2);
	for(int i=3;i<1'000'000;i+=2)
		if(!p.test(i))
		{
			a.pb(i);
			for(int j=i*3;j<1'000'000;j+=i<<1) p.set(j);
		}
	m=n;
	for(auto &i: a)
		if(n%i==0)
		{
			m/=i;
			m*=(i-1);
			for(; n%i==0; n/=i);
		}
	if(n!=1) m/=n,m*=(n-1);
	cout<<m;
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
