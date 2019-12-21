#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 510

int n,m;

struct vect
{
    int x,y,z;
    vect()
    {
        x=0; y=0; z=0;
    }
    vect(int p,int q,int r)
    {
        x=p; y=q; z=r;
    }
    vect vecplus(vect p)
    {
        return vect(x+p.x,y+p.y,z+p.z);
    }
    vect vecminus(vect p)
    {
        return vect(x-p.x,y-p.y,z-p.z);
    }
    vect crossp(vect p)
    {
        return vect(y*p.z-z*p.y,z*p.x-x*p.z,x*p.y-y*p.x);
    }
    double dotp(vect p)
    {
        return (double)x*p.x+y*p.y+z*p.z;
    }
    double siz()
    {
        return sqrt(x*x+y*y+z*z);
    }
    void consmul(int c)
    {
        x*=c; y*=c; z*=c;
    }
};

int main(){
    //freopen("input.txt","r",stdin);
    //scanf("%d %d",&n,&m);
    int a,b,c,d,e,f;
    scanf("%d %d %d %d %d %d",&a,&b,&c,&d,&e,&f);
    vect g=vect(c-a,d-b,0);
    vect ans=g.crossp(vect(e-c,f-d,0));
    if(!ans.z) printf("0");
    else if(ans.z>0) printf("1");
    else printf("-1");
    return 0;
}
