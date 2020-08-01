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

int n,m,l;
vi a,b;
ll d[3010][3010],dp[3010][3010][2];

void Solve()
{
    cin>>n>>m>>l;
    a.resize(n); b.resize(m);
    for(auto &i:a) cin>>i;
    for(auto &i:b) cin>>i;
    for(int i=n;i--;)
        for(int j=m;j--;) d[i][j]=(ll)l*l + (ll)(a[i]-b[j])*(a[i]-b[j]);

    ll now=0;
    for(int i=0;i<n;i++)
    {
        dp[i][0][0] = now + d[i][0] * (i+1) * (n+m-i-1);
        now += d[i][0] * (n+m-1);
    }
//    for(int i=0;i<n;i++)
//        cout<<i<<' '<<dp[i][0][0]<<'\n';

    now=0;
    for(int i=0;i<m;i++)
    {
        dp[0][i][1] = now + d[0][i] * (i+1) * (n+m-i-1);
        now += d[0][i] * (n+m-1);
    }
//    for(int i=0;i<m;i++)
//        cout<<i<<' '<<dp[i][0][0]<<'\n';

    for(int i=1;i<n;i++)
        for(int j=1;j<m;j++)
        {
            dp[i][j][0]=min(d[i][j] * (n+m-1) + dp[i][j-1][0], d[i][j] * (i+j+1) * (n+m-i-j-1) + dp[i-1][j][1]);
            dp[i][j][1]=min(d[i][j] * (n+m-1) + dp[i-1][j][1], d[i][j] * (i+j+1) * (n+m-i-j-1) + dp[i][j-1][0]);
//            cout<<"----\n";
//            cout<<i<<' '<<j<<'\n';
//            cout<<dp[i][j][0]<<' '<<dp[i][j][1]<<'\n';
        }

    if(n==1||m==1) cout<<max(dp[n-1][m-1][0],dp[n-1][m-1][1]);
    else cout<<min(dp[n-1][m-1][0],dp[n-1][m-1][1]);
}

int main(){
   // freopen("input.txt","r",stdin);
//    int tc; cin>>tc; while(tc--)
    Solve();
    return 0;
}
