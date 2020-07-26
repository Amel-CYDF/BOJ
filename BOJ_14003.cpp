#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define pb push_back
#define ff first
#define ss second
#define MOD 998244353
#define N 1000000
#define M 3010

int n,m,a[N+10],b[N+10],c[N+10],d[N+10];

void Solve()
{
    cin>>n;
    for(int i=0;i<n;i++) scanf("%d",a+i);
    for(int i=0;i<n;i++)
    {
        c[i]=lower_bound(b,b+m,a[i])-b;
        b[c[i]]=a[i];
        if(c[i]==m) m++;
    }
    cout<<m<<'\n';
    for(int i=n,j=m-1;i--;)
        if(c[i]==j) d[j--]=a[i];
    for(int i=0;i<m;i++) printf("%d ",d[i]);
}

int main(){
  //  freopen("input.txt","r",stdin);
//    int tc; cin>>tc; while(tc--)
    Solve();
    return 0;
}

