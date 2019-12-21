#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define N 20
#define M 0
#define MOD 15746

struct amel
{
    int s,e,w;
    bool operator<(const amel &rhs)const
    {
        return e<rhs.e;
    }
}a[N];

int n,m,ans[N],dap;

int main(){
    //freopen("input.txt","r",stdin);
    cin>>n;
    for(int i=0,s;i<n;i++)
        cin>>s>>a[i].w,a[i].s=i+1,a[i].e=i+s;
    sort(a,a+n);
    for(int i=0;i<n&&a[i].e<=n;i++)
    {
        for(int j=0;j<i;j++)
            if(a[j].e<a[i].s) ans[i]=max(ans[i],ans[j]);
        ans[i]+=a[i].w;
        dap=max(dap,ans[i]);
    }
    cout<<dap;
    return 0;
}
