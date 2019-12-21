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

int n;

int main(){
 //   freopen("input.txt","r",stdin);
    cin>>n;
    if(n<11) printf("1");
    else if(n<111) printf("2");
    else if(n<1111) printf("3");
    else if(n<11111) printf("4");
    else if(n<111111) printf("5");
    else if(n<1111111) printf("6");
    else if(n<11111111) printf("7");
    else if(n<111111111) printf("8");
    else printf("9");
    return 0;
}
