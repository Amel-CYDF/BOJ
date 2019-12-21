#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define N 510
#define M 0
#define MOD 15746

int n,m;

void amel(int p,int s,int e)
{
    if(!p) return;
    int tmp=6-s-e;
    amel(p-1,s,tmp);
    printf("%d %d\n",s,e);
    amel(p-1,tmp,e);
}

int main(){
    //freopen("input.txt","r",stdin);
    cin>>n;
    printf("%d\n",(1<<n)-1);
    amel(n,1,3);
    return 0;
}
