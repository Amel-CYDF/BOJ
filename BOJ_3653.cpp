#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct bit
{
    int a[1<<20],siz;

    void init(int p)
    {
        for(siz=1;siz<p;siz<<=1);
        memset(a+1,0,sizeof(int)*siz);
    }

    void add(int pos,int p)
    {
        while(pos<=siz)
        {
            a[pos]+=p;
            pos+= pos&-pos;
        }
    }

    int sum(int pos)
    {
        int ret=0;
        while(pos)
        {
            ret+=a[pos];
            pos^= pos&-pos;
        }
        return ret;
    }
};

int n,m,b[1<<20];
bit bb;

int main(){
  //  freopen("input.txt","r",stdin);
    int te;
    scanf("%d",&te);
    while(te--)
    {
        memset(b,0,sizeof(b));
        scanf("%d %d",&n,&m);
        bb.init(m+n);
        for(int i=1;i<=n;i++) b[i]=m+i,bb.add(m+i,1);
        for(int i=m,s;i;i--)
            scanf("%d",&s),printf("%d ",bb.sum(b[s]-1)),bb.add(b[s],-1),bb.add(i,1),b[s]=i;
        puts("");
    }
    return 0;
}
