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

int n,m,a[15],ans=INT_MAX;
vpii b,c;

int amel()
{
	int ret=0;
	for(int i=c.size(); i--; )
	{
		int tmp=INT_MAX;
		for(int j=b.size(); j--; )
			if(a[j]) tmp=min(tmp, abs(c[i].ff-b[j].ff)+abs(c[i].ss-b[j].ss));
		ret+=tmp;
	}
	return ret;
}

void Solve()
{
	cin>>n>>m;
	for(int i=n; i--; )
		for(int j=n,k; j--; )
		{
			cin>>k;
			if(k==1) c.pb(mp(i,j));
			else if(k==2) b.pb(mp(i,j));
		}
	for(int i=m; i--; ) a[i]=1;
	do
	{
		ans=min(ans, amel());
	}while(prev_permutation(a,a+b.size()));
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
