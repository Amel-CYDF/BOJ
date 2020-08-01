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

int n,m,dp[1005][1005][105],ans,sum[1005][1005];
vi a;

void Solve()
{
    cin>>n;
    a.resize(n);
    for(auto &i:a) cin>>i;

    if(n==1) {cout<<a[0]; return;}

    for(int i=n;i--;)
        for(int t=101;t--;) dp[i][i][t]=a[i];

    for(int i=n;i--;)
    {
        sum[i][i]=a[i];
        for(int j = (i-1+n) % n; j!=i ;j = (j-1+n) % n)
            sum[j][i]=sum[(j+1)%n][i]+a[j];
    }

    for(int d=1;d<n-1;d++)
        for(int i=n, j = (n-1+d) % n; i--; j = (j-1+n) % n)
            for(int t=101;t--;)
            {
                if(t>=a[i])
                    dp[i][j][t]=max(dp[i][j][t], a[i] + dp[(i+1)%n][j][t-a[i]]);
                else
                    dp[i][j][t]=max(dp[i][j][t], sum[i][j] - dp[(i+1)%n][j][a[i]-t-1]);

                if(t>=a[j])
                    dp[i][j][t]=max(dp[i][j][t], a[j] + dp[i][(j-1+n)%n][t-a[j]]);
                else
                    dp[i][j][t]=max(dp[i][j][t], sum[i][j] - dp[i][(j-1+n)%n][a[j]-t-1]);
            }
    for(int i=n;i--;) ans=max(ans, sum[0][n-1] - dp[(i+1)%n][(i-1+n)%n][a[i]-1]);
    cout<<ans<<'\n';
}

int main(){
  //  freopen("input.txt","r",stdin);
//    int tc; cin>>tc; while(tc--)
    Solve();
    return 0;
}