#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define N 15
#define M 61
#define MOD 10007

int n,m,a[N][N],ans[10010];

int findint(int p[][N])
{
    int ret=0;
    for(int i=2;i<n;i++)
        for(int j=2;j<m;j++)
            if(p[i][j]=='R') p[i][j]='.',ret+=n*m*(i*m+j);
            else if(p[i][j]=='B') p[i][j]='.',ret+=i*m+j;
    return ret;
}

int amel(int p[][N],int d)
{
    int red=0;
    for(int ii=(d&2?m:n)-3;ii--;)
        for(int i=2;i<(d&2?n:m);i++)
        {
            int x=d&1?1:-1;
            for(int j=(d&1?2:(d&2?m-1:n-1));j>1&&j<(d&2?m:n);j+=x)
            {
                if(d&2&&(p[i][j]=='.'||p[i][j]=='O'))
                {
                    if(p[i][j+x]=='R')
                    {
                        if(p[i][j]=='O') red=1,p[i][j+x]='.';
                        else p[i][j]='R',p[i][j+x]='.';
                    }
                    else if(p[i][j+x]=='B')
                    {
                        if(p[i][j]=='O') return -1;
                        p[i][j]='B'; p[i][j+x]='.';
                    }
                }
                else if(!(d&2)&&(p[j][i]=='.'||p[j][i]=='O'))
                {
                    if(p[j+x][i]=='R')
                    {
                        if(p[j][i]=='O') red=1,p[j+x][i]='.';
                        else p[j][i]='R',p[j+x][i]='.';
                    }
                    else if(p[j+x][i]=='B')
                    {
                        if(p[j][i]=='O') return -1;
                        p[j][i]='B'; p[j+x][i]='.';
                    }
                }
            }
        }
    return red?0:findint(p);
}

bool dobfs()
{
    int f=findint(a);
    memset(ans,-1,sizeof(ans));
    queue<int> bfs;
    bfs.push(f); ans[f]=0;
    while(!bfs.empty())
    {
        int p=bfs.front(); bfs.pop();
        if(ans[p]==10) return 1;
        int tmp[N][N]; memcpy(tmp,a,sizeof(a));
        int red=p/(n*m),blue=p%(n*m);
        tmp[red/m][red%m]='R'; tmp[blue/m][blue%m]='B';
        for(int i=0;i<4;i++)
        {
            int b[N][N]; memcpy(b,tmp,sizeof(tmp));
            int r=amel(b,i);
            if(r<0||ans[r]>=0) continue;
            ans[r]=ans[p]+1;
            if(!r) return 0;
            bfs.push(r);
        }
    }
    return 1;
}

int main(){
   // freopen("input.txt","r",stdin);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++) scanf(" %c",a[i]+j);
    if(dobfs()) {printf("-1"); return 0;}
    printf("%d",ans[0]);
    return 0;
}
