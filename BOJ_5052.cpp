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
vector<string> a;

bool amel(string &p,string &q)
{
	int i=0;
	for(; i<p.size()&&i<q.size(); i++)
		if(p[i]!=q[i]) break;
	return i>=p.size() | i>=q.size();
}

void Solve()
{
	cin>>n;
	a.resize(n);
	for(auto &i: a) cin>>i;
	sort(a.begin(),a.end());
	for(int i=n-1;i--;)
		if(amel(a[i],a[i+1])) {cout<<"NO\n"; return;}
	cout<<"YES\n";
}

void Init(bool isLocal){ if(isLocal) freopen("input.txt","r",stdin);
	ios::sync_with_stdio(false); cin.tie(NULL);
}
int main(){ Init(01);
	int tc; cin>>tc; for(int i=1;i<=tc;i++)
//	cout<<"Case #"<<i<<'\n',
	Solve();
	return 0;
}

