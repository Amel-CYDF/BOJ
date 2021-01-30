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

int n,m,k,s,e,a[1010][1010];
struct node
{
	int s,e,v;
};
vector<node> ed;

void Solve()
{
	cin>>n>>m>>k>>s>>e;
	ed.resize(m);
	for(auto &i:ed) cin>>i.s>>i.e>>i.v;
	memset(a,0x77,sizeof(a));
	a[s][0]=0;
	for(int i=1;i<n;i++)
		for(auto &j:ed)
			a[j.s][i]=min(a[j.s][i],a[j.e][i-1]+j.v),
			a[j.e][i]=min(a[j.e][i],a[j.s][i-1]+j.v);
	int r=0;
	cout<<*min_element(a[e],a[e]+n)<<'\n';
	for(int i; k--;)
	{
		cin>>i;
		r+=i;
		ll w=LLONG_MAX;
		for(int i=n;i--;)
			w=min(w,a[e][i]+(ll)i*r);
		cout<<w<<'\n';
	}
}

void Init(bool isLocal=0){ if(isLocal) freopen("input.txt","r",stdin);
	ios::sync_with_stdio(false); cin.tie(NULL);
}
int main(){ Init(1);
//	int tc; cin>>tc; for(int i=1;i<=tc;i++)
//	cout<<"Case #"<<i<<'\n',
	Solve();
	return 0;
}
