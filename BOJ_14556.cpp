#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,ll> pii;
#define pb push_back
#define ff first
#define ss second
#define N 50010
#define M 25
#define MOD 1000000009

int n,m;
ll a=1;

int main(){
  //  freopen("input.txt","r",stdin);
    cin>>n;
    for(;n;n--) a*=(n<<1)-1,a%=MOD;
    cout<<a;
    return 0;
}
