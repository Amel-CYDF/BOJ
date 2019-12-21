#include <bits/stdc++.h>
using namespace std;

int n,len=1,a[100010],ans,lf[100010],ri[100010],tr[400010];

int trfind(int st,int ed)
{
    st+=len; ed+=len;
    if(st>ed) return 0;

    int val=0;
    while(st<ed)
    {
        if(st%2) val+=tr[st++];
        if(ed%2==0) val+=tr[ed--];
        if(st<ed) st>>=1,ed>>=1;
    }
    return val+tr[st];
}

void trins(int val,int pos)
{
    pos+=len;
    while(pos>0) tr[pos]+=val,pos>>=1;
}

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",a+i);

    for(ans=n-1;ans>0&&a[ans-1]<a[ans];ans--);
    printf("%d\n",ans);

    int cnt=0,idx=ans;
    for(int i=1;i<=n;i++)
        i==a[idx]?cnt++,idx++:ri[i]=cnt;

    pair<int,int> amel[ans+5];
    for(int i=0;i<ans;i++) amel[i]={a[i],i};
    sort(amel,amel+ans);

    while(len<n) len<<=1;
    for(int i=0;i<ans;i++)
    {
        idx=amel[i].second;
        lf[idx]=trfind(0,idx-1);
        trins(1,idx);
    }

    for(int i=0;i<ans;i++)
        printf("%d ",ans-i-1+lf[i]+ri[a[i]]);

    return 0;
}
