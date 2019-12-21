#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000

ll a[55][55],d[55][55];
int n;
ll m;

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

ll (*amel(ll p[][55],ll q))[55]
{
    if(!q) return d;
    return q&1ll?mul(p,amel(mul(p,p),q>>1)):amel(mul(p,p),q>>1);
}

int main(){
  //  freopen("input.txt","r",stdin);
    scanf("%d %lld",&n,&m);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++) scanf("%d",a[i]+j);
    for(int i=0;i<n;i++) d[i][i]=1;
    ll (*ans)[55];
    ans=amel(a,m);
    for(int i=0;i<n;i++,puts(""))
        for(int j=0;j<n;j++) printf("%lld ",ans[i][j]);

    return 0;
}
