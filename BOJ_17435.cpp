#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define pb push_back
#define ff first
#define ss second
#define N 500010
#define M 25
#define MOD 998244853

int n,a[N][M];

int main(){
   // freopen("input.txt","r",stdin);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i][0];
    for(int j=1;j<20;j++)
        for(int i=1;i<=n;i++) a[i][j]=a[a[i][j-1]][j-1];
    cin>>n;
    for(int p,q;~scanf("%d %d",&p,&q);printf("%d\n",q))
        for(int i=0;p>>i;i++)
            if(p>>i&1) q=a[q][i];
    return 0;
}
