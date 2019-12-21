#include <bits/stdc++.h>
using namespace std;

int n,a[1000010],b[1000010];


int main(){
   // freopen("input.txt","r",stdin);

    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",a+i);
    for(int i=0;i<n;i++) scanf("%d",b+i);

    int pos=0,now=1;
    while(a[pos]!=b[0]) pos++;

    bool can=0;
    for(int i=pos+1;;i++,i%=n,now++)
    {
        if(i==pos) {can=1; break;}
        if(a[i]!=b[now]) break;
    }
    now=1;
    for(int i=pos-1;;i+=n-1,i%=n,now++)
    {
        if(i==pos) {can=1; break;}
        if(a[i]!=b[now]) break;
    }

    printf(can?"good puzzle":"bad puzzle");

    return 0;
}
