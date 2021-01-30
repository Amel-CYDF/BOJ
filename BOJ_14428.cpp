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

int n,m,a[300'010];

void upd(int pos,int p)
{
	a[pos|=m]=p;
	for(pos>>=1;pos;pos>>=1) a[pos]=min(a[pos<<1],a[pos<<1|1]);
}

int amel(int lf,int rg)
{
	lf|=m; rg|=m;
	vpii t;
	while(lf<rg)
	{
		if(lf&1) t.pb(mp(a[lf],lf)),lf++;
		else if(~rg&1) t.pb(mp(a[rg],rg)),rg--;
		else lf>>=1,rg>>=1;
	}
	t.pb(mp(a[lf],lf));
	auto r=min_element(t.begin(),t.end())->ff;
	int ret=INT_MAX;
	for(auto &i:t)
		if(i.ff==r)
		{
			int t=i.ss;
			for(;~t&m;)
			{
				if(a[t<<1]==r) t<<=1;
				else t=t<<1|1;
			}
			ret=min(ret,t);
		}
	return ret^m;
}

void Solve()
{
	cin>>n;
	memset(a,0x77,sizeof(a));
	for(m=1;m<n;m<<=1);
	for(int i=0;i<n;i++) cin>>a[i|m];
	for(int i=m;i--;) a[i]=min(a[i<<1],a[i<<1|1]);
	int tc; cin>>tc;
	for(int r,i,j;tc--;)
	{
		cin>>r>>i>>j;
		if(r&1) upd(i-1,j);
		else cout<<amel(i-1,j-1)+1<<'\n';
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
