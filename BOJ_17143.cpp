#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define N 110
#define MOD 15746

int n,m,k,b[N][N],ans,tmp[N][N];

struct shark
{
    int v,d,z;
    pii amel(pii p)
    {
        if(d)
        {
            if(p.second+v<=m||(m<<1)-p.second-v<1)
                return {p.first,p.second+v<=m?(p.second+v):(2-(m<<1)+p.second+v)};
            v=(m-1<<1)-v; return {p.first,2-p.second+v};
        }
        if(p.first+v<=n||(n<<1)-p.first-v<1)
            return {p.first+v<=n?(p.first+v):(2-(n<<1)+p.first+v),p.second};
        v=(n-1<<1)-v; return {2-p.first+v,p.second};
    }
    bool operator<(const shark &rhs)const
    {
        return z<rhs.z;
    }
}a[N*N];

int main(){
  //  freopen("input.txt","r",stdin);
    scanf("%d %d %d",&n,&m,&k);
    for(int i=1,s,t;i<=k;i++)
    {
        scanf("%d %d %d %d %d",&s,&t,&a[i].v,&a[i].d,&a[i].z);
        b[s][t]=i;
        if(!(a[i].d&2)) a[i].v=-a[i].v;
        a[i].d=(a[i].d>2);
        a[i].v%=(a[i].d?m:n)-1<<1;
        if(a[i].v<0) a[i].v+=(a[i].d?m:n)-1<<1;
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++) if(b[j][i]) {ans+=a[b[j][i]].z; b[j][i]=0; break;}
        memset(tmp,0,sizeof(tmp));
        for(int x=1;x<=n;x++)
            for(int y=1;y<=m;y++)
                if(b[x][y])
                {
                    pii t=a[b[x][y]].amel({x,y});
                    if(!tmp[t.first][t.second]||a[tmp[t.first][t.second]]<a[b[x][y]])
                        tmp[t.first][t.second]=b[x][y];
                }
        memcpy(b,tmp,sizeof(tmp));
    }
    printf("%d",ans);
    return 0;
}
