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
vi a;

void Solve()
{
	cin>>n;
	a.resize(n);
	for(auto &i: a) cin>>i;
	sort(a.begin(),a.end());
	for(int i=4; i<n-2; i++)
	{
		int t=0;
		for(int j=i-4; j<i; j++) t+=a[j];
		int p=t-a[i];
		auto rr=lower_bound(a.begin()+i+1, a.end(), p);
		int r=rr-a.begin()-1;
		if(r<=i) continue;
		r=min(r,n-2);
		if(a[r+1]-a[r]>=a[i])
		{
			for(int j=r-1; j>i; j--)
				if(a[j+1]-a[j]<a[i])
				{
					m=max(m, t+a[i]+a[j]+a[j+1]);
					break;
				}
		}
		else
		{
			rr=lower_bound(a.begin()+r+1, a.end(), a[i]+a[r]);
			p=rr-a.begin()-1;
			if(p>r) m=max(m, t+a[i]+a[r]+a[p]);
		}
	}
	cout<<(m ? m : -1);
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
