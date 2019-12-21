#include <bits/stdc++.h>
using namespace std;

int n,m,k,stx,sty,edx,edy;
int a[1010][1010];

queue<pair<int,int> > myque;


int main(){
    scanf("%d %d %d",&n,&m,&k);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++) scanf(" %c",&a[i][j]);
    scanf("%d %d %d %d",&stx,&sty,&edx,&edy);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++) a[i][j]=='.'?a[i][j]=INT_MAX:a[i][j]=-1;
    a[stx][sty]=0;
    myque.push({stx,sty});

    while(!myque.empty())
    {
        pair<int,int> t=myque.front(); myque.pop();
        int now=a[t.first][t.second];

        for(int x=t.first+1;x<=n&&x<=t.first+k&&a[x][t.second]>=now+1;x++) if(a[x][t.second]>now+1) a[x][t.second]=now+1,myque.push({x,t.second});
        for(int x=t.first-1;x>0&&x>=t.first-k&&a[x][t.second]>=now+1;x--) if(a[x][t.second]>now+1) a[x][t.second]=now+1,myque.push({x,t.second});
        for(int y=t.second+1;y<=m&&y<=t.second+k&&a[t.first][y]>=now+1;y++) if(a[t.first][y]>now+1) a[t.first][y]=now+1,myque.push({t.first,y});
        for(int y=t.second-1;y>0&&y>=t.second-k&&a[t.first][y]>=now+1;y--) if(a[t.first][y]>now+1) a[t.first][y]=now+1,myque.push({t.first,y});
    }

    if(a[edx][edy]==INT_MAX) printf("-1");
    else printf("%d",a[edx][edy]);


    return 0;
}
