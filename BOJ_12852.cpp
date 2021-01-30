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

int n,m,a[1'000'010];
queue<int> b;

void Solve()
{
	cin>>n;
	memset(a,-1,sizeof(a));
	b.push(n); a[n]=a[0]=0;
	while(!b.empty())
	{
		int t=b.front(); b.pop();
		if(t%3==0 && !~a[t/3]) a[t/3]=t, b.push(t/3);
		if(~t&1 && !~a[t>>1]) a[t>>1]=t, b.push(t>>1);
		if(!~a[t-1]) a[t-1]=t, b.push(t-1);
	}
	vi ans;
	for(int i=1; i!=n; i=a[i]) ans.pb(i);
	ans.pb(n);
	cout<<ans.size()-1<<'\n';
	for(int i=ans.size(); i--;) cout<<ans[i]<<' ';
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
