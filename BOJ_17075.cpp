#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define N 55
#define MOD 10007

int n,m,k,a[N][N],ans[N*N][2510],d[N][N];

int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d %d %d",&n,&m,&k);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++) scanf("%d",a[i]+j);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++) d[i][j]=(i*(n-i+1)*j*(m-j+1))%k;
    ans[m][0]=1;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            int x=i*m+j;
            if(a[i][j]<=0) for(int r=0;r<k;r++) ans[x][r]=ans[x-1][r];
            if(a[i][j]) for(int r=0;r<k;r++) if(ans[x-1][r]) ans[x][(r+d[i][j])%k]=1;
        }

    if(!ans[n*m+m][0]) {printf("-1"); return 0;}
    printf("1\n");
    int now=0;
    for(int i=n;i;i--)
        for(int j=m;j;j--)
        {
            if(a[i][j]<0) a[i][j]=!ans[i*m+j-1][now];
            if(a[i][j]) now=(now+k-d[i][j])%k;
        }
    for(int i=1;i<=n;i++,puts(""))
        for(int j=1;j<=m;j++) printf("%d ",a[i][j]);
    return 0;
}
