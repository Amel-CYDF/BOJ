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

int n,m;
int a,b,c,d,e,f;

void Solve()
{
    cin>>a>>b>>c>>d>>e>>f;
    printf("%d %d\n",(c*e-f*b)/(a*e-d*b), (c*d-f*a)/(b*d-e*a));
}

int main(){
   // freopen("input.txt","r",stdin);
//    int tc; cin>>tc; while(tc--)
    Solve();
    return 0;
}
