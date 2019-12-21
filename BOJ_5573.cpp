#include <bits/stdc++.h>
using namespace std;

int n,m,k;
bool a[1010][1010];
int b[1010][1010];

int main(){
    scanf("%d %d %d",&n,&m,&b[1][1]); b[1][1]--;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++) scanf("%d",&a[i][j]);

    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            b[i][j+1]+=b[i][j]/2+(b[i][j]%2&&a[i][j]);
            b[i+1][j]+=b[i][j]/2+(b[i][j]%2&&!a[i][j]);
        }

    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++) if(b[i][j]%2) a[i][j]=!a[i][j];

    int x=1,y=1;
    while(x!=n+1&&y!=m+1) a[x][y]?y++:x++;
    printf("%d %d",x,y);

    return 0;
}
