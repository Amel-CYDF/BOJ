#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct line
{
    ll s,i;
};

struct stk
{
    line a[1<<20];
    double b[1<<20];
    int siz;
    line linetop()
    {
        return a[siz];
    }
    double pttop()
    {
        return b[siz];
    }
    void pop()
    {
        siz--;
    }
    void push(line p,double q)
    {
        a[++siz]=p,b[siz]=q;
    }
    void print()
    {
        printf("size: %d\n",siz);
        printf("line:\n");
        for(int i=1;i<=siz;i++) printf("%lld %lld\n",a[i].s,a[i].i);
        printf("point: ");
        for(int i=1;i<=siz;i++) printf("%3.3f\n",b[i]);
        puts("");
    }
}a;

int n;
ll c1,c2,c3,sum;

double cross(line p,line q)
{
    return (double)(p.i-q.i)/(q.s-p.s);
}

int main(){
   // freopen("input.txt","r",stdin);
    scanf("%d",&n);
    scanf("%lld %lld %lld",&c1,&c2,&c3);
    a.push({0ll,0ll},-10000);
    for(int i=1,s,now=INT_MAX;;i++)
    {
        //a.print();
        scanf("%d",&s); sum+=(ll)s;
        if(a.siz<now) now=a.siz;
        else
        {
            if(now>1) now--;
            while(now<a.siz&&(double)sum>=a.b[now+1]) now++;
        }
        ll ans=a.a[now].s*sum+a.a[now].i+c1*sum*sum+c2*sum+c3;
        if(i==n) {printf("%lld",ans); break;}

        line tmp={-2*c1*sum,ans+c1*sum*sum-c2*sum};
        while(cross(tmp,a.linetop())<=a.pttop()) a.pop();
        a.push(tmp,cross(tmp,a.linetop()));
        //printf("%lld\n",ans);
    }
    return 0;
}
