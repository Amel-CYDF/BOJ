#include <cstdio>
int a[10010],n;
int main(){
    scanf("%d",&n);
    while(~scanf("%d",&n)) a[n]++;
    for(int i=1;i<10010;i++)
        while(a[i]--) printf("%d\n",i);
    return 0;
}
