#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define N 100010
#define M 0
#define MOD 15746

int n,m;

int amel(int p)
{
    int ret=0;
    for(;p;p/=10) ret*=10,ret+=p%10;
    return ret;
}

int main(){
 //   freopen("input.txt","r",stdin);
    cin>>n>>m;
    printf("%d",max(amel(n),amel(m)));
    return 0;
}
