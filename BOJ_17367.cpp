#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
#define pb push_back
#define ff first
#define ss second
#define MOD 1000000007
#define N 100010
#define M 3010
#define SOURCE 51
#define SINK 52

int n,m;
double a[10][10][1010],ans;

int amel(int p,int q,int r)
{
    if(p==q&&q==r) return 10000+p*1000;
    if(p==q) return 1000+p*100;
    if(q==r) return 1000+q*100;
    if(r==p) return 1000+r*100;
    return 100*max(p,max(q,r));
}

void Solve()
{
    cin>>n;
    for(int i=1;i<=n-2;i++)
        for(int j=1;j<=6;j++)
            for(int k=1;k<=6;k++)
            {
                for(int r=1;r<=6;r++)
                {
                    a[j][k][i]+=max((double)amel(j,k,r), a[k][r][i-1]);
                }
                a[j][k][i]/=6;
            }
    for(int i=1;i<=6;i++)
        for(int j=1;j<=6;j++) ans+=a[i][j][n-2];
    printf("%.6f",ans/36);
}

int main(){
//    freopen("input.txt","r",stdin);
//    int tc; cin>>tc; while(tc--)
    Solve();
    return 0;
}
