#include <bits/stdc++.h>
using namespace std;

int n,k,vis[110][210];
long long a[1010][1010],d[110][210],ans;

void chk(int x,int y)
{
    if(vis[x][y]) return;
    for(int i=1;d[x+i][y+i]!=4;i++) vis[x+i][y+i]=1;
    for(int i=x;i<x+k;i++)
        for(int j=y;j<y+k;j++)
            if(d[i][j]!=a[i-x][j-y]) return;
    ans+=max(0LL,(long long)n-k+1-max(x,y)+1);
}

int main(){
  //  freopen("input.txt","r",stdin);

    for(int i=0;i<110;i++)
        for(int j=0;j<210;j++) d[i][j]=4;
    d[1][1]=d[1][2]=1;
    for(int i=3;i<=92;i++) d[1][i]=d[1][i-1]+d[1][i-2];
    for(int i=2;i<=94;i++)
    {
        d[i][1]=d[i-1][2]-d[i-1][1];
        for(int j=2;d[i-1][j-1]!=4;j++) d[i][j]=d[i-1][j-1];
    }

    scanf("%d %d",&n,&k);
    for(int i=0;i<k;i++)
        for(int j=0;j<k;j++) scanf("%lld",a[i]+j);

    if(k<=185)
    {
        for(int i=1;i<=94-k+1;i++)
            for(int j=1;d[i][j+k-1]!=4;j++)
                chk(i,j);
    }

    printf("%lld",ans);

    return 0;
}
