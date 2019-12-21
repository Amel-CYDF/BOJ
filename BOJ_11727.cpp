#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define N 1010
#define M 0
#define MOD 10007

int n,m=0,k=1,r;

int main(){
  //  freopen("input.txt","r",stdin);
    cin>>n;
    while(n--) r=(k+(m<<1))%MOD,m=k,k=r;
    cout<<k;
    return 0;
}
