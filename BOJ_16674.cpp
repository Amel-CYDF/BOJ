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

ll n;
int a[10];

int main(){
 //   freopen("input.txt","r",stdin);
    cin>>n;
    for(;n;n/=10) a[n%10]++;
    if(a[3]||a[4]||a[5]||a[6]||a[7]||a[9]) {printf("0"); return 0;}
    if(!a[0]||!a[1]||!a[2]||!a[8]) {printf("1"); return 0;}
    if(a[0]!=a[1]||a[1]!=a[2]||a[2]!=a[8]) printf("2");
    else printf("8");
    return 0;
}
