#include <bits/stdc++.h>
using namespace std;
int n,m,a[1010][1010],ans;
int u[4]={1,-1},v[4]={0,0,1,-1};
queue<int>q;
int bfs()
{
    if(q.empty()) return 0;
    int x=q.front(); q.pop();
    int y=q.front(); q.pop();
    for(int i=0;i<4;i++)
        if(0<x+u[i]&&x+u[i]<=n&&0<y+v[i]&&y+v[i]<=m&&!a[x+u[i]][y+v[i]])
        {
            a[x+u[i]][y+v[i]]=a[x][y]+1;
            q.push(x+u[i]);
            q.push(y+v[i]);
        }
    return 1;
}
 
int main(){
  //  freopen("input.txt","r",stdin);
    scanf("%d %d",&m,&n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            scanf("%d",&a[i][j]);
            if(a[i][j]==1)
            {
                q.push(i);
                q.push(j);
            }
        }
    while(bfs());
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            if(!a[i][j])
            {
                printf("-1");
                return 0;
            }
            ans=max(ans,a[i][j]);
        }
    printf("%d",ans-1);
    return 0;
}