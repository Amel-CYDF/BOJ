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
vpii ans;

void makeed(int p,int q)
{
    ans.pb({p+1, q+1});
}

void Solve()
{
    cin>>n;
    makeed(0, 2);
    makeed(1, 2);
    makeed(2, 3);
    makeed(3, 4);
    switch(n%6)
    {
        case 0:
            makeed(4, 5); break;
        case 1:
            makeed(3, 5); makeed(5, 6); break;
        case 2:
            makeed(4, 5); makeed(4, 6); makeed(6, 7); break;
        case 3:
            makeed(0, 5); makeed(1, 6); makeed(2, 7); makeed(7, 8); break;
        case 4:
            makeed(4, 5); makeed(3, 6); makeed(6, 7); makeed(3, 8); makeed(8, 9); break;
        case 5:
            makeed(0, 5); makeed(2, 6); makeed(6, 7); makeed(7, 8); makeed(8, 9); makeed(9, 10);
    }
    for(m=n%6+6;m<n;m+=6)
    {
        makeed(m-1, m);
        makeed(m-1, m+2);
        makeed(m-1, m+4);
        makeed(m, m+1);
        makeed(m+2, m+3);
        makeed(m+4, m+5);
    }
    for(auto i:ans) cout<<i.ff<<' '<<i.ss<<'\n';
}

int main(){
//    freopen("input.txt","r",stdin);
//    int tc; cin>>tc; while(tc--)
    Solve();
    return 0;
}
