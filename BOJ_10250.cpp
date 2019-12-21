#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define N 15
#define M 61
#define MOD 10007

int n,m,k;

int main(){
 //   freopen("input.txt","r",stdin);
    int te; cin>>te;
    while(~scanf("%d %d %d",&n,&m,&k)) printf("%d%02d\n",k%n?k%n:n,(k-1)/n+1);
    return 0;
}
