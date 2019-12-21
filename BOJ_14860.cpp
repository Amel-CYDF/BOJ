#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define pb push_back
#define ff first
#define ss second
#define MOD 1000000007
#define N 2010
#define M 62510

int n,m,b;
ll ans=1;
bool p[15000010]={1,1};

ll amel(ll p,ll q)
{
    if(!q) return 1;
    return q&1?amel(p*p%MOD,q>>1)*p%MOD:amel(p*p%MOD,q>>1);
}

int main(){
   // freopen("input.txt","r",stdin);
    cin>>n>>m;
    b=max(n,m);
    for(int i=3;i<=b;i+=2)
        if(!p[i])
            {for(int j=i<<1;j<=b;j+=i) p[j]=1;}
    for(int i=2;i<=b;i==2?i++:i+=2)
        if(!p[i])
            {for(ll j=i;j<=b;j*=i)
                ans=ans*amel((ll)i,(ll)(n/j)*(m/j))%MOD;}
    cout<<ans;
    return 0;
}
