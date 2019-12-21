#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define pb push_back
#define ff first
#define ss second
#define N 7
#define M 12
#define MOD 998244853

int n,m,a[M][4][N][N],b[M][4][N][N],ans,c[M]={3,2,1};

void upd(int p[][N],int q[][N])
{
    int ret=0;
    for(int i=0;i<5;i++)
        for(int j=0;j<5;j++)
            switch(q[i][j])
            {
                case 1: ret+=7*p[i][j]; break;
                case 2: ret+=5*p[i][j]; break;
                case 3: ret+=3*p[i][j]; break;
                case 4: ret+=p[i][j]<<1; break;
            }
    ans=max(ans,ret);
}

void amel(int p[][N],int q[][N],int s[][N],int t[][N],int x,int y)
{
    for(int i=x;i<x+4;i++)
        for(int j=y;j<y+4;j++)
        {
            p[i][j]+=s[i-x][j-y];
            if(p[i][j]<0) p[i][j]=0;
            else if(p[i][j]>9) p[i][j]=9;
            if(t[i-x][j-y]) q[i][j]=t[i-x][j-y];
        }
}

void arrrot(int p[][N],int q[][N])
{
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            p[i][j]=q[3-j][i];
}

int main(){
   // freopen("input.txt","r",stdin);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<4;j++)
            for(int k=0;k<4;k++) scanf("%d",a[i][0][j]+k);
        for(int j=1;j<4;j++) arrrot(a[i][j],a[i][j-1]);
        for(int j=0;j<4;j++)
            for(int k=0;k<4;k++) scanf(" %c",b[i][0][j]+k);
        for(int j=0;j<4;j++)
            for(int k=0;k<4;k++)
                switch(b[i][0][j][k])
                {
                    case'W': b[i][0][j][k]=0; break;
                    case'R': b[i][0][j][k]=1; break;
                    case'B': b[i][0][j][k]=2; break;
                    case'G': b[i][0][j][k]=3; break;
                    case'Y': b[i][0][j][k]=4; break;
                }
        for(int j=1;j<4;j++) arrrot(b[i][j],b[i][j-1]);
    }
    do
    {
        for(int rot=0;rot<1<<6;rot++)
            for(int loc=0;loc<1<<6;loc++)
            {
                int p[N][N]={},q[N][N]={};
                for(int i=0;i<3;i++)
                {
                    int now=0,nrot=rot>>(i<<1)&3;
                    while(c[now]!=i+1) now++;
                    amel(p,q,a[now][nrot],b[now][nrot],loc>>(i<<1)&1,loc>>(i<<1)+1&1);
                }
                upd(p,q);
            }
    }while(prev_permutation(c,c+n));
    cout<<ans;
    return 0;
}
