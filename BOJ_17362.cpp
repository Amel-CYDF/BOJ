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

int n;

void Solve()
{
    cin>>n;
    n--; n%=8; n++;
    switch(n)
    {
        case 1: cout<<1; break;
        case 2: case 8: cout<<2; break;
        case 3: case 7: cout<<3; break;
        case 4: case 6: cout<<4; break;
        default: cout<<5;
    }
}

int main(){
//    freopen("input.txt","r",stdin);
//    int tc; cin>>tc; while(tc--)
    Solve();
    return 0;
}
