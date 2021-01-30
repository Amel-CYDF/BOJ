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
ll a[1'00'010][10];
int b[8][8]={/*
0 1 2 3 4 5 6 7*/
0,1,1,0,0,0,0,0,
1,0,1,1,0,0,0,0,
1,1,0,1,1,0,0,0,
0,1,1,0,1,1,0,0,
0,0,1,1,0,1,1,0,
0,0,0,1,1,0,0,1,
0,0,0,0,1,0,0,1,
0,0,0,0,0,1,1,0
};

void Solve()
{
	cin>>n;
	a[n][0]=1;
	for(int i=n; i--;)
		for(int j=8; j--;)
			for(int k=8; k--;)
				if(b[j][k]) a[i][k]=(a[i][k]+a[i+1][j])%MOD;
	cout<<a[0][0];
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
