#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define N 100010
#define M 0
#define MOD 10007

int n,m,a[N][2],b[N][2];

int main(){
   // freopen("input.txt","r",stdin);
    int te; cin>>te;
    while(te--)
    {
        memset(a,0,sizeof(a));
        cin>>n;
        for(int j=0;j<2;j++)
            for(int i=1;i<=n;i++) cin>>b[i][j];
        a[1][0]=b[1][0]; a[1][1]=b[1][1];
        for(int i=2;i<=n;i++)
        {
            a[i][0]=a[i][1]=max(a[i-2][0],a[i-2][1]);
            a[i][0]=max(a[i][0],a[i-1][1]);
            a[i][1]=max(a[i][1],a[i-1][0]);
            a[i][0]+=b[i][0]; a[i][1]+=b[i][1];
        }
        cout<<max(max(a[n-1][0],a[n-1][1]),max(a[n][0],a[n][1]))<<"\n";
    }
    return 0;
}
