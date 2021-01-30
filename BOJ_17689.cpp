#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define MOD 1000000007

int n,m;
ll ans;

typedef pair<int,ll> pil;

struct cmp
{
	bool operator()(const pil &lhs,const pil &rhs)const
	{
		if(lhs.ss!=rhs.ss) return lhs.ss>rhs.ss;
		return lhs.ff<rhs.ff;
	}
};

set<pil,cmp> b;
set<pil> c;

void Solve()
{
	cin>>n;
	for(int i=n,j;i--;)
	{
		cin>>j;
		b.insert(mp(i,j));
		c.insert(mp(i,j));
	}
	for(n=n+1>>1;n--;)
	{
		auto t=*b.begin(); b.erase(b.begin());
		auto r=c.find(t);
		auto lf=r,rg=r; ++rg;
		ans+=t.ss;
		t.ss=-t.ss;
		bool fl=true;
		if(rg!=c.end())
		{
			t.ss+=rg->ss;
			b.erase(*rg);
			++rg;
		}
		else fl=false;
		if(lf!=c.begin())
		{
			--lf;
			t.ss+=lf->ss;
			b.erase(*lf);
		}
		else fl=false;
		c.erase(lf,rg);
		if(fl) b.insert(t),c.insert(t);
		cout<<ans<<'\n';
	}
}

void Init(bool isLocal){ if(isLocal) freopen("input.txt","r",stdin);
//	ios::sync_with_stdio(false); cin.tie(NULL);
}
int main(){ Init(01);
//    int tc; cin>>tc; while(tc--)
    Solve();
    return 0;
}
