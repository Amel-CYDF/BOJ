#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define pb push_back
#define ff first
#define ss second
#define MOD 1000000009
#define N 300010
#define M 62510

int n;
pii a[N];

bool cmp(pii lhs,pii rhs)
{
    return lhs.ss<rhs.ss;
}

bool possible(ll p)
{
    int hi,pos=1;
    while(pos<=n&&(ll)a[pos].ss<=p>>1) pos++;
    for(int i=2;i--;)
    {
        ll d=min_element(a+pos,a+n+1,cmp)->ss+p;
        for(hi=a[pos].ss;pos<=n;pos++)
        {
            hi=max(hi,a[pos].ss);
            if((ll)hi>d) break;
        }
    }
    return pos>n;
}

int main(){
  //  freopen("input.txt","r",stdin);
    cin>>n;
    for(int i=1;i<=n;i++) scanf("%d %d",&a[i].ff,&a[i].ss);
    sort(a+1,a+n+1);
    ll lf=0,rg=INT_MAX;
    if(!a[1].ff) lf=(ll)a[1].ss<<1;
    while(lf<rg)
    {
        ll mid=lf+rg>>1;
        if(possible(mid)) rg=mid;
        else lf=mid+1;
    }
    printf("%.1f",lf/2.0);
    return 0;
}
