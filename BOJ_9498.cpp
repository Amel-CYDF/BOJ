#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
#define N 1000010
#define MOD 1000000007

int n,m,k;

int main(){
  //  freopen("input.txt","r",stdin);
    scanf("%d",&n);
    if(n>=90) printf("A");
    else if(n>=80) printf("B");
    else if(n>=70) printf("C");
    else if(n>=60) printf("D");
    else printf("F");
    return 0;
}
