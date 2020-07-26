#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define pb push_back
#define ff first
#define ss second
#define MOD 600921647
#define N 500000
#define M 3010

int n,m,tridx=1<<20;

struct pst
{
    int val;
    pst *lf,*rg;
}tr[(1<<20)+N*20+10],*a[N+10];

void push(int p)
{
    auto tmp=a[n];
    a[++n]=tr + tridx;
    for(int i=19;i--;tridx++)
    {
        tr[tridx].val=tmp->val+1;
        if(p>>i & 1) tr[tridx].lf = tmp->lf, tr[tridx].rg = tr+tridx+1, tmp=tmp->rg;
        else tr[tridx].rg = tmp->rg, tr[tridx].lf = tr+tridx+1, tmp=tmp->lf;
    }
    tr[tridx++].val=tmp->val+1;
}

int xox(int st,int ed,int p)
{
    int ret=0;
    auto lf=a[st-1],rg=a[ed];
    for(int i=19;i--;)
    {
        ret<<=1;
        if(p>>i & 1)
        {
            if(lf->lf->val==rg->lf->val)
                lf=lf->rg,rg=rg->rg,ret|=1;
            else lf=lf->lf,rg=rg->lf;
        }
        else
        {
            if(lf->rg->val==rg->rg->val)
                lf=lf->lf,rg=rg->lf;
            else lf=lf->rg,rg=rg->rg,ret|=1;
        }
    }
    return ret;
}

int sma(int st,int ed,int p)
{
    p++;
    int ret=0;
    auto lf=a[st-1],rg=a[ed];
    for(int i=19;i--;)
    {
        if(p>>i & 1)
            ret+=rg->lf->val-lf->lf->val,lf=lf->rg,rg=rg->rg;
        else
            lf=lf->lf,rg=rg->lf;
    }
    return ret;
}

int kth(int st,int ed,int p)
{
    int ret=0;
    auto lf=a[st-1],rg=a[ed];
    for(int i=19;i--;)
    {
        ret<<=1;
        if(rg->lf->val - lf->lf->val < p)
            p-=rg->lf->val - lf->lf->val,lf=lf->rg,rg=rg->rg,ret|=1;
        else
            lf=lf->lf,rg=rg->lf;
    }
    return ret;
}

int main(){
  //  freopen("input.txt","r",stdin);
    /*
int tc; cin>>tc;
while(tc--)
{//*/

    cin>>m;
    for(int i=1;i<1<<19;i++)
    {
        tr[i].lf = tr + i*2;
        tr[i].rg = tr + i*2 + 1;
    }
    a[0]=tr+1;
    for(int i,j,k;m--;)
    {
        scanf("%d",&i);
        switch(i)
        {
            case 1: scanf("%d",&i); push(i); break;
            case 2: scanf("%d %d %d",&i,&j,&k); printf("%d\n",xox(i,j,k)); break;
            case 3: scanf("%d",&i); n-=i; break;
            case 4: scanf("%d %d %d",&i,&j,&k); printf("%d\n",sma(i,j,k)); break;
            case 5: scanf("%d %d %d",&i,&j,&k); printf("%d\n",kth(i,j,k));
        }
    }

    /*
}//*/
    return 0;
}
