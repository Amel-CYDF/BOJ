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

int n,m,b[1'00'10];
vi a;
vvi ans;

void Solve()
{
	cin>>n>>m;
	a.resize(n);
	for(auto &i: a) cin>>i;
	sort(a.begin(),a.end());
	for(int i=m; i--; ) b[i]=1;
	do
	{
		vi tmp;
		for(int i=n; i--; ) if(b[i]) tmp.pb(a[i]);
		do
		{
			ans.pb(tmp);
		}while(prev_permutation(tmp.begin(),tmp.end()));
	}while(prev_permutation(b,b+n));
	sort(ans.begin(),ans.end());
	for(auto &i: ans)
	{
		for(auto &j: i) cout<<j<<' ';
		cout<<'\n';
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
