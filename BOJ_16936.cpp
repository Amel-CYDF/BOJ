#include <bits/stdc++.h>
using namespace std;

long long a[110];

int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%lld",a+i);
    sort(a,a+n,[](long long p,long long q){
        while(!(p%3||q%3)) p/=3,q/=3;
        if(p%3&&q%3)
        {
            while(!(p%2||q%2)) p/=2,q/=2;
            return p%2;
        }
        return q%3;
    });
    for(int i=0;i<n;i++) printf("%lld ",a[i]);
    return 0;
}
