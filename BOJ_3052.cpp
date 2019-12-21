#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define N 310
#define MOD 1000000007

int n,m;
set<int> ans;

int main(){
  //  freopen("input.txt","r",stdin);
    while(~scanf("%d",&n)) ans.insert(n%42);
    printf("%d",ans.size());
    return 0;
}
