#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,pii> piii;
#define N 15
#define M 100010
#define MOD 10007

int n,m,a[N][N];

int main(){
  //  freopen("input.txt","r",stdin);
    cin>>n>>m;
    for(int i=0;i<=n;i++)
    {
        a[i][0]=1;
        for(int j=1;j<=i;j++)
            a[i][j]=a[i-1][j-1]+a[i-1][j];
    }
    cout<<a[n][m];
    return 0;
}
