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

vector<pair<int, pii>> a;
vpii b;
vector<set<pii>> dp;

bool cmp(const int &p, const pii &q)
{
	auto t=dp[p].upper_bound(mp(q.ff,INT_MAX));
	if(t==dp[p].begin()) return false;
	--t;
	return t->ss < q.ss;
}

void Solve()
{
	cin>>m>>n;
	a.resize(n);
	for(auto &i:a) cin>>i.ff;
	for(auto &i:a) cin>>i.ss.ff;
	if(m==3)
	{
		for(auto &i:a) cin>>i.ss.ss;
	}
	sort(a.begin(),a.end());
	for(auto &i:a) b.pb(i.ss);
	if(m==2)
	{
		for(int i=n;i--;) b[i].ss=i;
	}
	for(auto &i:b)
	{
		int lf=0,rg=dp.size();
		while(lf<rg)
		{
			int mid=lf+rg>>1;
			if(cmp(mid,i)) lf=mid+1;
			else rg=mid;
		}
		if(lf==dp.size()) dp.resize(dp.size()+1), dp.rbegin()->insert(i);
		else
		{
			auto t=dp[lf].upper_bound(mp(i.ff,INT_MAX));
			while(t!=dp[lf].end() && t->ss >= i.ss) t=dp[lf].erase(t);
			dp[lf].insert(t,i);
		}
	}
	cout<<dp.size();
}

void Init(bool isLocal){ if(isLocal) freopen("input.txt","r",stdin);
	ios::sync_with_stdio(false); cin.tie(NULL);
}
int main(){ Init(01);
//    int tc; cin>>tc; while(tc--)
    Solve();
    return 0;
}
