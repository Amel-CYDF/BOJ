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

int n,m,b[1010],c[1010];
vi a;

void Solve()
{
	cin>>n;
	a.resize(n);
	for(auto &i: a) cin>>i;
	for(int i=n; i--;) b[i]=c[i]=1;
	for(int i=0;i<n;i++)
		for(int j=0;j<i;j++)
			if(a[j]<a[i]) b[i]=max(b[i],b[j]+1);
	for(int i=n; i--; )
		for(int j=i+1; j<n; j++)
			if(a[j]<a[i]) c[i]=max(c[i],c[j]+1);
	int ans=0;
	for(int i=n; i--;) ans=max(ans,b[i]+c[i]);
	cout<<ans-1;
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
