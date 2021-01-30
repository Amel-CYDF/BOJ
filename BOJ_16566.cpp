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

int n,m,k,a[4'000'010],b[4'000'010];

int parfind(int p)
{
	if(a[p]==p) return p;
	return a[p]=parfind(a[p]);
}

void uni(int p,int q)
{
	a[parfind(p)]=parfind(q);
}

void Solve()
{
	cin>>n>>m>>k;
	for(int i=m;i--;) cin>>b[i];
	sort(b,b+m);
	for(int i=m+1;i--;) a[i]=i;
	for(int i;k--;)
	{
		cin>>i;
		auto t=upper_bound(b,b+m,i)-b;
		cout<<b[parfind(t)]<<'\n';
		uni(t,a[t]+1);
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

