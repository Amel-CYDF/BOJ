#include <bits/stdc++.h>
using namespace std;

int n,a[110],ans=INT_MAX,dap,now[110],cnt;

int gcd(int p,int q)
{
    if(!p||!q) return p|q;

    if(q==1) {now[cnt++]=p-1; dap+=p-1; return 1;}

    int ret=gcd(q,p%q);
    now[cnt++]=p/q;
    dap+=p/q;
    return ret;
}

bool comp()
{
    if(ans!=dap) return ans>dap;
    for(int i=0;a[i]&&now[i];i++)
        if(a[i]!=now[i]) return (i%2)^(a[i]<now[i]);
}

int main(){
 //   freopen("input.txt","r",stdin);

    scanf("%d",&n);

    for(int i=1;i<n;i++)
    {
        for(int j=0;j<cnt;j++) now[j]=0;
        dap=cnt=0;
        if(gcd(n,i)>1) continue;
        if(comp())
        {
            ans=dap;
            for(int j=0;a[j]||now[j];j++) a[j]=now[j];
        }
    }

    for(int i=0;a[i];i++)
        for(int j=0;j<a[i];j++) printf(i%2?"Y":"X");

    return 0;
}
