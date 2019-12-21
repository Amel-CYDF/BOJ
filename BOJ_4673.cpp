#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define pb push_back
#define ff first
#define ss second
#define MOD 1000000007
#define N 200010
#define M 100010

bool a[10010];

int main()
{
//    freopen("input.txt","r",stdin);
    for(int i=1,k;i<=10000;i++)
    {
        if(!a[i]) printf("%d\n",i);
        k=i;
        for(int j=i;j;j/=10) k+=j%10;
        a[k]=1;
    }
    return 0;
}
