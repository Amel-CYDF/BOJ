#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define MOD 1000000007
#define N 100010
#define M 3010
#define SOURCE 51
#define SINK 52

int n,m,k,dp[30][200010];
ll ans;
vector<string> a;
string b;

void Solve()
{
    cin>>n>>m>>k;
    a.resize(k);
    for(auto &i:a) cin>>i;
    cin>>b;
    for(int i=k;i--;)
        for(int j=0,now=-1;j<m;j++)
        {
            if(a[i][j]=='U') now=j;
            dp[i][j]=now;
        }
    int lf=m-1,rg=m-1;
    if(m>1) lf=dp[b.back()-'A'][m-2]+1;
    ans=rg-lf+1;
    b.pop_back();
    reverse(b.begin(), b.end());
    for(auto i:b)
    {
        i-='A';
        int nlf = lf;
        if(lf>0) nlf = dp[i][lf-1]+1;
        int nrg = dp[i][rg];
        if(nrg<lf) break;

        lf=nlf; rg=nrg;
        ans+=rg-lf+1;
    }
    cout<<ans;
}

int main(){
   // freopen("input.txt","r",stdin);
//    int tc; cin>>tc; while(tc--)
    Solve();
    return 0;
}
