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
vi a,b;

void Solve()
{
	cin>>n;
	a.resize(n);
	for(auto &i: a) cin>>i;
	b=a;
	sort(b.begin(),b.end());
	b.resize(unique(b.begin(),b.end())-b.begin());
	for(auto &i: a)
		cout<<(lower_bound(b.begin(),b.end(),i)-b.begin())<<' ';
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
