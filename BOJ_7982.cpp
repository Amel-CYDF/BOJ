#include <bits/stdc++.h>
using namespace std;

int n,a[1000010],ind[1000010],now,cnt;
vector<int> ed;

int bisearch(int p)
{
    int lf=0,rg=ed.size()-1;
    while(lf<rg)
    {
        int mid=(lf+rg)/2;
        if(ed[mid]>=p) rg=mid;
        else lf=mid+1;
    }
    return lf;
}

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",a+i),ind[a[i]]=i;

    for(int i=1;i<=n;i++)
    {
        if(now<ind[i]) ed.push_back(ind[i]),now=ind[i];
        else
        {
            int k=bisearch(ind[i]);
            ed[k]=now;
            while(ed.size()>k+1) ed.pop_back();
        }
    }

    printf("%d\n",ed.size());
    for(int i=0;i<ed.size();i++)
    {
        int pre=i?ed[i-1]:0;
        printf("%d ",ed[i]-pre);
        set<int> myset;
        for(int j=pre+1;j<=ed[i];j++) myset.insert(a[j]);
        for(int j:myset) printf("%d ",j);
        printf("\n");
    }
    return 0;
}
