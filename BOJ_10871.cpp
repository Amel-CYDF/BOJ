#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define N 10010
#define MOD 1000000007

int n,m;

int main(){
  //  freopen("input.txt","r",stdin);
    scanf("%d %d",&n,&m);
    while(~scanf("%d",&n))
        if(n<m) printf("%d ",n);
    return 0;
}
