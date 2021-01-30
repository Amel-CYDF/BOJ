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

int n,m,r;
struct node
{
	int v,s,e;
};
vector<node> a,b;

bool cmps(const node &lhs,const node &rhs)
{
	return lhs.s<rhs.s;
}
bool cmpe(const node &lhs,const node &rhs)
{
	return lhs.e<rhs.e;
}
set<int> c;

void Solve()
{
	cin>>n;
	a.resize(n);
	for(int i=n;i--;)
	{
		cin>>a[i].s>>a[i].e,a[i].v=i;
		if(a[i].s>a[i].e) swap(a[i].s,a[i].e);
	}
	cin>>m;
	b=a;
	sort(a.begin(),a.end(),cmps);
	sort(b.begin(),b.end(),cmpe);
	int lf=0,rg=0;
	for(auto &i:a)
	{
		for(;lf<n&&a[lf].s<i.s;lf++) c.erase(a[lf].v);
		for(;rg<n&&b[rg].e<=(ll)i.s+m; rg++)
			if(b[rg].s>=i.s) c.insert(b[rg].v);
		r=max(r,(int)c.size());
	}
	cout<<r;
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

