#include<bits/stdc++.h>
using namespace std;

struct qwe{
    long long up;
    long long down;
    int num;
    bool operator<(const qwe z)const{
        if(up!=z.up) return up<z.up;
        return down<z.down;
    }
};

bool cmp(qwe x,qwe y){
    return x.down < y.down;
}


long long i,j,b[2][100010],n,l;
long long dp[2][100010];
qwe a[100010];

int main(){
    scanf("%lld %lld",&n,&l);
    for(i=0;i<n;i++){
        scanf("%lld %lld",&a[i].up,&a[i].down);

    }
    sort(a,a+n);
    for(i=0;i<n;i++){
        a[i].num=i;
    }
    b[0][0]=1;
    for(i=1;i<n;i++){
        if(a[i].up==a[i-1].up){
            b[0][i]=b[0][i-1];
        }
        else{
            b[0][i]=b[0][i-1]+1;
        }
    }
    sort(a,a+n,cmp);
    b[1][a[0].num]=1;
    for(i=1;i<n;i++){
        if(a[i].down==a[i-1].down){
            b[1][a[i].num]=b[1][a[i-1].num];
        }
        else{
            b[1][a[i].num]=b[1][a[i-1].num]+1;
        }
    }
    sort(a,a+n);
    /*
    for(i=0;i<2;i++){
        for(j=0;j<n;j++){
            printf("%d ",b[i][j]);
        }
        printf("\n");
    }
    */
    for(i=0;i<n;i++){
        long long k=a[i].num;
        long long t1=dp[0][b[0][k]],t2=dp[1][b[1][k]];
        dp[0][b[0][k]]=(long long)max(dp[0][b[0][k]],t2+abs(a[i].up-a[i].down)+l);
        dp[1][b[1][k]]=(long long)max(dp[1][b[1][k]],t1+abs(a[i].up-a[i].down)+l);
    }
    printf("%lld",max(*max_element(dp[0],dp[0]+n),*max_element(dp[1],dp[1]+n)));
}
