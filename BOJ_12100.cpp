#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define N 25
#define M 0
#define MOD 15746

int n,m,a[N][N],ans;

void amel(int p[][N],int d)
{
    int tmp[N][N]={},ret[N][N]={};
    for(int i=1;i<=n;i++)
        for(int cnt=1,j=d&1?n:1;j&&j<=n;d&1?j--:j++)
        {
            if(d&2&&p[i][j]) tmp[i][cnt++]=p[i][j];
            else if(!(d&2)&&p[j][i]) tmp[i][cnt++]=p[j][i];
        }
    for(int i=1;i<=n;i++)
        for(int j=1,cnt=d&1?n:1;tmp[i][j];j++)
        {
            if(tmp[i][j]==tmp[i][j+1])
            {
                d&2?ret[i][cnt]=tmp[i][j]<<1:ret[cnt][i]=tmp[i][j]<<1;
                j++;
            }
            else d&2?ret[i][cnt]=tmp[i][j]:ret[cnt][i]=tmp[i][j];
            d&1?cnt--:cnt++;
        }
    memcpy(p,ret,sizeof(ret));
}

int main(){
 //   freopen("input.txt","r",stdin);
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++) cin>>a[i][j];
    for(int i=0;i<1<<10;i++)
    {
        int tmp[N][N];
        memcpy(tmp,a,sizeof(a));
        for(int j=i,r=5;r;r--,j>>=2)
            amel(tmp,j&3);
        for(int j=1;j<=n;j++)
            for(int k=1;k<=n;k++) ans=max(ans,tmp[j][k]);
    }
    printf("%d",ans);
    return 0;
}
