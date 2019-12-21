#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 25
#define MOD 1000000007

int n,m,ti;
ll d[N][N],a[110][N][N],ans[N][N];

void mul(ll p[][N],ll q[][N])
{
    ll res[N][N];
    memset(res,0,sizeof(res));
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            for(int k=0;k<n;k++)
                res[i][j]+=p[i][k]*q[k][j],
                res[i][j]%=MOD;
    memcpy(p,res,sizeof(res));
}

void amel(ll p[][N],int q)
{
    if(!q) {memcpy(p,d,sizeof(d)); return;}
    ll psq[N][N];
    memcpy(psq,p,sizeof(psq));
    mul(psq,p); amel(psq,q>>1);
    if(q&1) mul(psq,p);
    memcpy(p,psq,sizeof(psq));
}

int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d %d %d",&m,&n,&ti);
    for(int i=0;i<n;i++) d[i][i]=ans[i][i]=1;
    for(int i=0,s;i<m;i++)
    {
        scanf("%d",&s);
        for(int j=0;j<s;j++)
        {
            int p,q; ll w;
            scanf("%d %d %lld",&p,&q,&w);
            a[i][p-1][q-1]=w;
        }
    }
    ll allmul[N][N];
    memcpy(allmul,d,sizeof(d));
    for(int i=0;i<m;i++) mul(allmul,a[i]);
    amel(allmul,ti/m);
    for(int i=0;i<ti%m;i++) mul(allmul,a[i]);
    for(int i=0;i<n;i++,puts(""))
        for(int j=0;j<n;j++) printf("%lld ",allmul[i][j]);
    return 0;
}