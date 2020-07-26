#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define pb push_back
#define ff first
#define ss second
#define MOD 1000
#define N 100010
#define M 3010

int n;
priority_queue<int> a;

int main(){
   // freopen("input.txt","r",stdin);
    cin>>n;
    for(int i;n--;)
    {
        scanf("%d",&i);
        if(i) a.push(i);
        else if(a.empty()) printf("0\n");
        else printf("%d\n",a.top()),a.pop();
    }
    return 0;
}
