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
const int r='.'-'A';
vpii a;

void geon(int p)
{
	if(p==r) return;
	cout<<(char)('A'+p);
	geon(a[p].ff); geon(a[p].ss);
}
void jung(int p)
{
	if(p==r) return;
	jung(a[p].ff);
	cout<<(char)('A'+p);
	jung(a[p].ss);
}
void hu(int p)
{
	if(p==r) return;
	hu(a[p].ff);
	hu(a[p].ss);
	cout<<(char)('A'+p);
}

void Solve()
{
	cin>>n;
	a.resize(n);
	for(int i=n; i--; )
	{
		char x,y,z;
		cin>>x>>y>>z;
		a[x-'A'].ff=y-'A'; a[x-'A'].ss=z-'A';
	}
	geon(0); cout<<'\n';
	jung(0); cout<<'\n';
	hu(0); cout<<'\n';
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

int n,m,a[510][510];

void Solve()
{
	cin>>n;
	for(int i=n; i--; )
	{
		for(int j=n-i,k; j--; )
			cin>>k,
			a[i][j]=max(a[i+1][j],a[i+1][j-1])+k;
	}
	cout<<*max_element(a[0],a[0]+n);
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
