#include <bits/stdc++.h>
using namespace std;

int a[15][15],ans=100,d[10]={0,5,5,5,5,5};

bool chk(int x,int y,int p)
{
    if(x+p-1>10||y+p-1>10) return 0;
    for(int i=x;i<x+p;i++)
        for(int j=y;j<y+p;j++)
            if(!a[i][j]) return 0;
    return 1;
}

void er(int x,int y,int p)
{
    for(int i=x;i<x+p;i++)
        for(int j=y;j<y+p;j++) a[i][j]=0;
}

void fil(int x,int y,int p)
{
    for(int i=x;i<x+p;i++)
        for(int j=y;j<y+p;j++) a[i][j]=1;
}

void amel(int x,int y,int p)
{
    if(x==10&&y==11) { ans=min(ans,p); return; }
    if(y>10) return amel(x+1,1,p);
    if(!a[x][y]) return amel(x,y+1,p);

    for(int i=1;i<6;i++)
        if(d[i])
        {
            if(!chk(x,y,i)) break;
            er(x,y,i); d[i]--;
            amel(x,y+1,p+1);
            fil(x,y,i); d[i]++;
        }
}

int main(){
 //   freopen("input.txt","r",stdin);

    for(int i=1;i<11;i++)
        for(int j=1;j<11;j++) scanf("%d",a[i]+j);

    amel(1,1,0);

    printf("%d",ans==100?-1:ans);

    return 0;
}
