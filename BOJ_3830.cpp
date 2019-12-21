#include <bits/stdc++.h>
using namespace std;

int n,m,par[100010];
long long dif[100010];

void init()
{
    for(int i=1;i<=n;i++) par[i]=i,dif[i]=0;
}

int pfind(int p)
{
    if(par[p]!=par[par[p]])
    {
        int ret=pfind(par[p]);
        dif[p]+=dif[par[p]];
        return par[p]=ret;
    }
    return par[p];
}

void uni(int p,int q,int w)
{
    int ppar=pfind(p),qpar=pfind(q);
    if(ppar==qpar) return;
    par[ppar]=qpar;
    dif[ppar]+=dif[q]-dif[p]-(long long)w;
}

int main(){
   // freopen("input.txt","r",stdin);

    do
    {
        scanf("%d %d",&n,&m);
        init();
        for(int i=0;i<m;i++)
        {
            char c;
            scanf(" %c",&c);
            int a,b,w;
            if(c=='!')
            {
                scanf("%d %d %d",&a,&b,&w);
                uni(a,b,w);
            }
            else
            {
                scanf("%d %d",&a,&b);
                if(pfind(a)!=pfind(b)) printf("UNKNOWN\n");
                else printf("%lld\n",dif[b]-dif[a]);
            }
        }

    }while(n||m);

    return 0;
}
