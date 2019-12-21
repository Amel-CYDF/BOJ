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



bool hap(ll p)
{
    bool ret=0;
    for(;p;p/=10) ret^=p&1;
    return ret;
}

ll last(ll p)
{
    for(;p>9;p/=10);
    return p;
}

ll amel(ll n)
{
    if(hap(n)) return n;
    ll zero=1;
    while(!(n%10)) n/=10,zero*=10;

    ll p=n,q=n;
    if((p/10)%10==9) p*=11;
    if(hap(p)) return p*zero;
    for(ll i=p%10;last(q)+i<10;q+=n) if(hap(q)) return q*zero;
    if(hap(q)) return q*zero;
    for(ll i=q/10;i;i/=10) p*=10;
    return (p+q)*zero;
}

int main(){
   // freopen("input.txt","r",stdin);
    int tc; cin>>tc;
    while(tc--)
    {
        ll p;
        cin>>p;
        printf("%lld\n",amel(p));
    }
    return 0;
}
