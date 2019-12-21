#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007

ll a[8][8]={
    0,1,1,0,0,0,0,0,
    1,0,1,1,0,0,0,0,
    1,1,0,1,1,0,0,0,
    0,1,1,0,1,1,0,0,
    0,0,1,1,0,1,0,1,
    0,0,0,1,1,0,1,0,
    0,0,0,0,0,1,0,1,
    0,0,0,0,1,0,1,0},
    d[8][8]={
    1,0,0,0,0,0,0,0,
    0,1,0,0,0,0,0,0,
    0,0,1,0,0,0,0,0,
    0,0,0,1,0,0,0,0,
    0,0,0,0,1,0,0,0,
    0,0,0,0,0,1,0,0,
    0,0,0,0,0,0,1,0,
    0,0,0,0,0,0,0,1};
int n;

ll (*mul(ll p[][8],ll q[][8]))[8]
{
    ll (*ret)[8]=new ll[8][8];
    for(int i=0;i<8;i++)
        for(int j=0;j<8;j++)
        {
            ret[i][j]=0;
            for(int s=0;s<8;s++)
                ret[i][j]+=p[i][s]*q[s][j],
                ret[i][j]%=MOD;
        }
    return ret;
}

ll (*amel(ll p[][8],int q))[8]
{
    if(!q) return d;
    return q&1?mul(p,amel(mul(p,p),q>>1)):amel(mul(p,p),q>>1);
}

int main(){
   // freopen("input.txt","r",stdin);
    scanf("%d",&n);
    ll (*ans)[8];
    ans=amel(a,n);
    printf("%lld",ans[0][0]);

    return 0;
}
