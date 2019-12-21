#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define pb push_back
#define ff first
#define ss second
#define MOD 1000000009
#define N 260
#define M 62510

int n,m,a[N][M],x[N],y[N],ans=INT_MAX;

int main(){
  //  freopen("input.txt","r",stdin);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>x[i]>>y[i];
    memset(a+1,1,sizeof(a)-sizeof(int)*M);
    for(int i=1;i<=n;i++)
        for(int j=0;j<M;j++)
        {
            if(a[i-1][j]<M) a[i][j]=min(a[i][j],a[i-1][j]+y[i]);
            if(j>=x[i]) a[i][j]=min(a[i][j],a[i-1][j-x[i]]);
        }
    for(int i=0;i<M;i++) ans=min(ans,max(i,a[n][i]));
    cout<<ans;
    return 0;
}
