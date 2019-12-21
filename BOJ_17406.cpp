#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define N 55
#define MOD 1000000007

int n,m,k,a[N][N],b[10][3],c[10],ans=INT_MAX,dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};

void amel(int p[][N],int sx,int sy,int q)
{
    for(int i=1;i<=q;i++)
        for(int x=sx-i,y=sy-i+1,d=0,pre=p[sx-i][sy-i];;x+=dx[d],y+=dy[d])
        {
            int tmp=p[x][y];
            p[x][y]=pre; pre=tmp;
            if(x==sx-i&&y==sy-i) break;
            if((x==sx+i||x==sx-i)&&(y==sy+i||y==sy-i)) d++,d%=4;
        }
}

int nina(int p[][N])
{
    int ret=INT_MAX;
    for(int i=1;i<=n;i++)
    {
        int tmp=0;
        for(int j=1;j<=m;j++) tmp+=p[i][j];
        ret=min(ret,tmp);
    }
    return ret;
}

int main(){
  //  freopen("input.txt","r",stdin);
    scanf("%d %d %d",&n,&m,&k);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++) scanf("%d",a[i]+j);
    for(int i=0;i<k;i++) scanf("%d %d %d",b[i],b[i]+1,b[i]+2);
    for(int i=0;i<k;i++) c[i]=i;
    for(int i=0;i<720;i++)
    {
        int tmp[N][N];
        memcpy(tmp,a,sizeof(a));
        for(int j=0;j<k;j++)
            amel(tmp,b[c[j]][0],b[c[j]][1],b[c[j]][2]);
        ans=min(ans,nina(tmp));
        next_permutation(c,c+k);
    }
    printf("%d",ans);
    return 0;
}
