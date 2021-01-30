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

int n,m,par[110];
typedef pair<double,double> pdd;
vector<pdd> a;

int parfind(int p)
{
	if(par[p]==p) return p;
	return par[p]=parfind(par[p]);
}

bool uni(int p,int q)
{
	p=parfind(p); q=parfind(q);
	if(p==q) return false;
	par[p]=q;
	return true;
}

struct amel
{
	int a,b;
	double val;
	bool operator<(const amel &rhs)const
	{
		return val<rhs.val;
	}
};
vector<amel> ed;

void Solve()
{
	cin>>n;
	a.resize(n);
	for(auto &i: a) cin>>i.ff>>i.ss;
	for(int i=n; i--;)
		for(int j=i;j--;) ed.pb({i,j,hypot(a[i].ff-a[j].ff,a[i].ss-a[j].ss)});
	sort(ed.begin(),ed.end());
	double ans=0;
	int cnt=n-1;
	for(int i=n;i--;) par[i]=i;
	for(auto &i: ed)
	{
		if(uni(i.a,i.b))
			cnt--,ans+=i.val;
		if(!cnt) break;
	}
	cout.precision(12);
	cout<<ans;
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
