#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007

ll a[55][55],d[55][55];
int n,m,t;

ll (*mul(ll p[][55],ll q[][55]))[55]
{
    ll (*ret)[55]=new ll[55][55];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        {
            ret[i][j]=0;
            for(int s=0;s<n;s++)
                ret[i][j]+=p[i][s]*q[s][j],
                ret[i][j]%=MOD;
        }
    return ret;
}

ll (*amel(ll p[][55],int q))[55]
{
    if(!q) return d;
    return q&1?mul(p,amel(mul(p,p),q>>1)):amel(mul(p,p),q>>1);
}

int main(){
//    freopen("input.txt","r",stdin);
    scanf("%d %d",&n,&m);
    for(int i=0,x,y;i<m;i++)
    {
        scanf("%d %d",&x,&y);
        a[x-1][y-1]=a[y-1][x-1]=1;
    }
    for(int i=0;i<n;i++) d[i][i]=1;
    scanf("%d",&t);
    ll (*ans)[55];
    ans=amel(a,t);
    printf("%lld",ans[0][0]);

    return 0;
}
