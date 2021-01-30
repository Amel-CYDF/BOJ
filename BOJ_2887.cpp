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

int n,m,a[100'010],toy[100'010],toz[100'010];
struct amel
{
	int x,y,z,v;
};

bool cmpx(const amel &lhs,const amel &rhs)
{
	return lhs.x<rhs.x;
}

bool cmpy(const amel &lhs,const amel &rhs)
{
	return lhs.y<rhs.y;
}

bool cmpz(const amel &lhs,const amel &rhs)
{
	return lhs.z<rhs.z;
}

vector<amel> x,y,z;

void Solve()
{
	cin>>n;
	x.resize(n);
	for(auto &i: x) cin>>i.x>>i.y>>i.z;
	sort(x.begin(),x.end(),cmpx);
	for(int i=n;i--;) x[i].v=i;
	y=z=x;
	sort(y.begin(),y.end(),cmpy);
	sort(z.begin(),z.end(),cmpz);
	for(int i=n;i--;) toy[y[i].v]=toz[z[i].v]=i;
	ll ans=0;
	priority_queue<pii> s;
	s.push(mp(0,0));
	for(int ii=n; ii--;)
	{
		auto t=s.top(); s.pop();
		if(a[t.ss]) {ii++; continue;}
		a[t.ss]=1;
		ans-=t.ff;
		int p=t.ss;
		if(p > 0) s.push(mp(x[p-1].x-x[p].x,p-1));
		if(p < n-1) s.push(mp(x[p].x-x[p+1].x,p+1));
		p=toy[t.ss];
		if(p > 0) s.push(mp(y[p-1].y-y[p].y,y[p-1].v));
		if(p < n-1) s.push(mp(y[p].y-y[p+1].y,y[p+1].v));
		p=toz[t.ss];
		if(p > 0) s.push(mp(z[p-1].z-z[p].z,z[p-1].v));
		if(p < n-1) s.push(mp(z[p].z-z[p+1].z,z[p+1].v));
	}
	cout<<ans;
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
