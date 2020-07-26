#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
#define pb push_back
#define ff first
#define ss second
#define MOD 1000000007
#define N 100010
#define M 3010
#define SOURCE 51
#define SINK 52

int n,m,odd;
int x,y;
vi a;

void Solve()
{
    cin>>n;
    a.resize(n);
    for(auto &i:a) cin>>i;
    for(auto i:a) m+=i, odd+=i&1;
    if(m%3 || m/3 < odd) {cout<<"NO"; return;}
    x=m/3; y=x-odd;
    for(auto &i:a) if(i&1) i^=1;
    for(auto &i:a)
    {
        x-= i>>1;
        if(x <= 0) {cout<<"YES"; return;}
    }
    cout<<"NO";
}

int main(){
   // freopen("input.txt","r",stdin);
//    int tc; cin>>tc; while(tc--)
    Solve();
    return 0;
}
