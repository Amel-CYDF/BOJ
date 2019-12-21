#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define pb push_back
#define ff first
#define ss second
#define MOD 1000000009
#define N 10010
#define M 62510

int n;
char a[N];

int main(){
  //  freopen("input.txt","r",stdin);
    cin>>n;
    for(int i=n;i--;)
    {
        scanf("%s",a);
        if(strlen(a)!=7) {printf("0\n"); continue;}
        if(a[0]==a[1]&&a[1]==a[4]&&a[2]==a[3]&&a[3]==a[5]&&a[5]==a[6]&&a[0]!=a[2]) printf("1\n");
        else printf("0\n");
    }
    return 0;
}
