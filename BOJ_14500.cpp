#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define N 510
#define M 61
#define MOD 10007

int n,m,a[N][N],ans;
int dx[19][4]=
    {0,0,0,0,
    0,1,2,3,
    0,0,1,1,
    0,1,2,2,
    0,1,2,2,
    0,0,1,2,
    0,0,1,2,
    0,0,0,-1,
    0,0,0,1,
    0,1,1,1,
    0,1,0,0,
    0,1,1,2,
    0,1,1,2,
    0,0,-1,-1,
    0,0,1,1,
    0,0,0,1,
    0,0,0,-1,
    0,1,1,2,
    0,1,1,2},
    dy[19][4]=
    {0,1,2,3,
    0,0,0,0,
    0,1,0,1,
    0,0,0,1,
    0,0,0,-1,
    0,1,0,0,
    0,1,1,1,
    0,1,2,2,
    0,1,2,2,
    0,0,1,2,
    0,0,1,2,
    0,0,1,1,
    0,0,-1,-1,
    0,1,1,2,
    0,1,1,2,
    0,1,2,1,
    0,1,2,1,
    0,0,1,0,
    0,0,-1,0};

bool chk(int x,int y)
{
    return 0<x&&x<=n&&0<y&&y<=m;
}

int amel(int x,int y,int k)
{
    int ret=0;
    for(int i=0;i<4;i++)
        if(chk(x+dx[k][i],y+dy[k][i])) ret+=a[x+dx[k][i]][y+dy[k][i]];
        else return 0;
    return ret;
}

int main(){
   // freopen("input.txt","r",stdin);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++) cin>>a[i][j];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            for(int k=0;k<19;k++) ans=max(ans,amel(i,j,k));
    cout<<ans;
    return 0;
}
