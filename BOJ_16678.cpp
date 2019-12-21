#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define pb push_back
#define ff first
#define ss second
#define MOD 1000000009
#define N 100010
#define M 62510

int n,a[N];
ll ans;

int main(){
   // freopen("input.txt","r",stdin);
    cin>>n;
    for(int i=1;i<=n;i++) scanf("%d",a+i);
    sort(a+1,a+n+1);
    for(int i=1,now=0;i<=n;i++)
    {
        if(a[i]!=now) now++;
        ans+=(ll)a[i]-now;
    }
    cout<<ans;
    return 0;
}
