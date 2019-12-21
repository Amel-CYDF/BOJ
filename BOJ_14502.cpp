#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define N 10
#define M 0
#define MOD 15746

int n,m,a[N][N],b[N][N],ans;
int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};

void dfs(int x,int y)
{
    if(a[x][y]) return;
    a[x][y]=2;
    for(int i=0;i<4;i++) dfs(x+dx[i],y+dy[i]);
}

void upd()
{
    int ret=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            ret+=!a[i][j];
    ans=max(ans,ret);
}

int main(){
   // freopen("input.txt","r",stdin);
    memset(b,-1,sizeof(b));
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++) cin>>b[i][j];
    for(int x1=1;x1<=n;x1++)
        for(int y1=1;y1<=m;y1++)
            for(int x2=x1;x2<=n;x2++)
                for(int y2=x2==x1?y1+1:1;y2<=m;y2++)
                    for(int x3=x2;x3<=n;x3++)
                        for(int y3=x3==x2?y2+1:1;y3<=m;y3++)
                            if(!b[x1][y1]&&!b[x2][y2]&&!b[x3][y3])
                            {
                                memcpy(a,b,sizeof(b));
                                a[x1][y1]=a[x2][y2]=a[x3][y3]=1;
                                for(int i=1;i<=n;i++)
                                    for(int j=1;j<=m;j++)
                                        if(a[i][j]==2) a[i][j]=0,dfs(i,j);
                                upd();
                            }
    cout<<ans;
    return 0;
}
