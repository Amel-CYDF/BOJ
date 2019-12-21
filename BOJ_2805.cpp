#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define N 1000010
#define M 0
#define MOD 15746

int n,m,a[N];

bool amel(int p)
{
    int ret=m;
    for(int i=0;i<n;i++)
    {
        ret-=max(0,a[i]-p);
        if(ret<=0) return 1;
    }
    return 0;
}

int main(){
   // freopen("input.txt","r",stdin);
    cin>>n>>m;
    for(int i=0;i<n;i++) cin>>a[i];
    int lf=0,rg=*max_element(a,a+n);
    while(lf<rg)
    {
        int mid=(lf+rg>>1)+1;
        if(amel(mid)) lf=mid;
        else rg=mid-1;
    }
    cout<<lf;
    return 0;
}
