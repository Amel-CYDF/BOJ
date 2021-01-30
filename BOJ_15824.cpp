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

int n,m;
ll b[300'010]={1};
vi a;

void Solve()
{
	cin>>n;
	a.resize(n);
	for(auto &i:a) cin>>i;
	sort(a.begin(),a.end());
	for(int i=1;i<n-1;i++) b[i]=(b[i-1]<<1)%MOD;
	ll lf=0,rg=0,ans=0;
	for(int i=n-1;i--;) rg+=b[i],rg%=MOD;
	for(int i=0;i<n;i++)
		ans+=(lf-rg)*a[i],ans%=MOD,rg-=b[n-2-i],rg%=MOD,lf+=b[i],lf%=MOD;
	cout<<(ans+MOD)%MOD;
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
