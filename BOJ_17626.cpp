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

int n,m,a[5'001'0];
vi b,c;

void Solve()
{
	for(int i = 1; i*i <= 5'000'0; i++)
		a[i*i]=1, b.pb(i*i);
	for(auto &i: b)
		for(auto &j: b)
			if(i+j<=5'000'0 && !a[i+j]) a[i+j]=2, c.pb(i+j);
	for(auto &i: b)
		for(auto &j: c)
			if(i+j<=5'000'0 && !a[i+j]) a[i+j] = 3;
	for(int i = 1; i<=5'000'0; i++) if(!a[i]) a[i]=4;
	cin>>n;
	cout<<a[n];
}

void Init(bool isLocal){ if(isLocal) freopen("input.txt","r",stdin);
	ios::sync_with_stdio(false); cin.tie(NULL);
}
int main(){ Init(01);
//	int tc; cin>>tc; for(int i=1;i<=tc;i++)
//	cout<<"if( b == #"<<i<<'\n',
	Solve();
	return 0;
}
