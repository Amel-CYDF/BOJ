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
string a;

bool amel()
{
	for(int i = a.size() + 1 >> 1; i--; )
		if(a[i] != a[a.size() - i - 1]) return false;
	return true;
}

void Solve()
{
	while(1)
	{
		getline(cin, a);
		if(a == "0") return;
		cout<< (amel() ? "yes\n" : "no\n");
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
