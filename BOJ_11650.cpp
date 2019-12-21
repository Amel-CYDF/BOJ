#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define N 100010
#define M 0
#define MOD 15746

int n,m;
pii a[N];

int main(){
//    freopen("input.txt","r",stdin);
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i].first>>a[i].second;
    sort(a,a+n);
    for(int i=0;i<n;i++) printf("%d %d\n",a[i].first,a[i].second);
    return 0;
}
