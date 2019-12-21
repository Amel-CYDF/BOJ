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

int n,a,b;
ll ans;

int main(){
    //freopen("input.txt","r",stdin);
    cin>>n>>a>>b;
    for(int i=1;i<=n;i++)
    {
        ans+=a*i+b*i*i;
    }
    cout<<ans;
    return 0;
}
