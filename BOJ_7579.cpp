#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define pb push_back
#define ff first
#define ss second
#define MOD 1000
#define N 100010
#define M 3010

int n,m,a[110][10010],p[110],q[110];

int main(){
  //  freopen("input.txt","r",stdin);
    cin>>n>>m;
    for(int i=1;i<=n;i++) scanf("%d",p+i);
    for(int i=1;i<=n;i++) scanf("%d",q+i);
    for(int i=1;i<=n;i++)
    {
        memcpy(a[i],a[i-1],sizeof(int)*10010);
        for(int j=q[i];j<=10000;j++) a[i][j]=max(a[i][j],a[i-1][j-q[i]]+p[i]);
    }
    for(int i=0;;i++)
        if(a[n][i]>=m) {cout<<i; break;}
    return 0;
}