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

int n,m;
list<int> a;

void Solve()
{
	cin>>n;
	for(string b; n--; )
	{
		cin>>b;
		if( b == "push_front") { cin>>m; a.push_front(m); }
		if( b == "push_back") { cin>>m; a.pb(m); }
		if( b == "pop_front") { if(a.empty()) cout<<"-1\n";
			else cout<<a.front()<<'\n', a.pop_front(); }
		if( b == "pop_back") { if(a.empty()) cout<<"-1\n";
			else cout<<a.back()<<'\n', a.pop_back(); }
		if( b == "size") { cout<<a.size()<<'\n'; }
		if( b == "empty") { cout<<a.empty()<<'\n'; }
		if( b == "front") { if(a.empty()) cout<<"-1\n";
			else cout<<a.front()<<'\n'; }
		if( b == "back") { if(a.empty()) cout<<"-1\n";
			else cout<<a.back()<<'\n'; }
	}
}

void Init(bool isLocal){ if(isLocal) freopen("input.txt","r",stdin);
	ios::sync_with_stdio(false); cin.tie(NULL);
}
int main(){ Init(01);
//	int tc; cin>>tc; for(int i=1;i<=tc;i++)
//	cout<<"if( b == #"<<i<<'\n',
	Solve();
	return 0;
}
