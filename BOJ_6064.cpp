#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define N 1010
#define M 1010
#define MOD 15746

int n,m,a,b;

int main(){
   // freopen("input.txt","r",stdin);
    int te; cin>>te;
    while(~scanf("%d %d %d %d",&n,&m,&a,&b))
    {
        if(a==n) a=0;
        if(b==m) b=0;
        te=0;
        for(int i=0;i<m;i++)
            if((i*n+a-b)%m==0) {te=1; printf("%d\n",i*n+a); break;}
        if(!te) printf("-1\n");
    }
    return 0;
}
