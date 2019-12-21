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

int n,m;
vector<int> a;

int main(){
  //  freopen("input.txt","r",stdin);
    cin>>n>>m;
    a.pb(1); a.pb(1);
    for(int p=1,q=1;;)
    {
        int tmp=(p+q)%m;
        p=q; q=tmp;
        if(tmp>99) a.pb(tmp/100);
        if(tmp>9) a.pb((tmp/10)%10);
        a.pb(tmp%10);
        if(p==1&&q==1) {a.pop_back(); a.pop_back(); break;}
    }
    for(ll i=n,j;i--;)
        scanf("%lld",&j),printf("%d\n",a[(j-1)%a.size()]);
    return 0;
}
