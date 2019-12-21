#include <bits/stdc++.h>
using namespace std;

int main(){
    int a[10];
    for(int i=0;i<8;i++) scanf("%d",a+i);
    if(is_sorted(a,a+8)) {printf("ascending"); return 0;}
    reverse(a,a+8);
    printf(is_sorted(a,a+8)?"descending":"mixed");
    return 0;
}
