#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define N 110
#define MOD 15746

int n,m,a[30];
char c;

int main(){
   // freopen("input.txt","r",stdin);
    memset(a,-1,sizeof(a));
    for(int i=0;~scanf(" %c",&c);i++) if(!(~a[c-'a'])) a[c-'a']=i;
    for(int i=0;i<26;i++) printf("%d ",a[i]);
    return 0;
}
