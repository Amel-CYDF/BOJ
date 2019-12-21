#include <bits/stdc++.h>
using namespace std;
#define mul(X) (X)*(X)

int n,testcase,ans;
unsigned int d[12501252];
pair<int,int> a[3010];

void init()
{
    ans=0;
}

void pointwrite(int x,int y)
{
    int t=(20001*x+y)/32,r=(20001*x+y)%32;
    d[t]^=1<<r;
}

bool exist(int x,int y)
{
    int t=(20001*x+y)/32,r=(20001*x+y)%32;
    return (d[t]>>r)%2;
}

bool isin(pair<int,int> p)
{
    return 0<=p.first&&p.first<=20000&&0<=p.second&&p.second<=20000;
}
int func(pair<int,int> p,pair<int,int> q)
{
    if(!isin(p)||!isin(q)) return 0;
    if(!exist(p.first,p.second)) return 0;
    if(!exist(q.first,q.second)) return 0;
    return mul(p.first-q.first)+mul(p.second-q.second);
}

int main(){
  //  freopen("input.txt","r",stdin);

    scanf("%d",&testcase);
    while(testcase--)
    {
        scanf("%d",&n);
        init();
        for(int i=0;i<n;i++) scanf("%d %d",&a[i].first,&a[i].second);
        for(int i=0;i<n;i++) a[i].first+=10000,a[i].second+=10000;
        for(int i=0;i<n;i++) pointwrite(a[i].first,a[i].second);
        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++)
            {
                int x=a[j].first-a[i].first,y=a[j].second-a[i].second;
                ans=max(ans,func({a[j].first+y,a[j].second-x},{a[i].first+y,a[i].second-x}));
                ans=max(ans,func({a[j].first-y,a[j].second+x},{a[i].first-y,a[i].second+x}));
            }
        printf("%d\n",ans);
        for(int i=0;i<n;i++) d[(20001*a[i].first+a[i].second)/32]=0;

    }

    return 0;
}
