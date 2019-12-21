#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define N 100010
#define M 0
#define MOD 15746

int n,m,k,ans[N];

int main(){
  //  freopen("input.txt","r",stdin);
    cin>>m>>n;
    while(~scanf("%d %d",&m,&k))
        for(int i=n;i>=m;i--)
            ans[i]=max(ans[i],ans[i-m]+k);
    cout<<ans[n];
    return 0;
}
