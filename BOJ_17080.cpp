#include <stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    printf("%d",1+(n%4==3));
    return 0;
}