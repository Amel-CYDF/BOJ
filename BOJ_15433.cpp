#include <bits/stdc++.h>
using namespace std;
#define tri(X) (X)*(X)*(X)
typedef pair<int,int> pii;

int n,k,cnt;

struct node
{
    int x;
    vector< pii > rag;
};

struct setcomp
{
    bool operator() (const node *lhs,const node *rhs)
    const{
        return lhs->x<rhs->x;
    }
};
set<node*,setcomp> myset;

int rad(int b)
{
    int val=ceil(cbrt((double)b));
    return tri(val)>b?val-1:val;
}

void nodeupdate(node *ptr,int st,int ed)
{
    if(myset.find(ptr)==myset.end()) myset.insert(ptr);
    node *val=*myset.find(ptr);
    val->rag.push_back({st,ed});
}

int main(){
    scanf("%d %d",&n,&k);
    for(int i=0;i<k;i++)
    {
        int p,q,b;
        scanf("%d %d %d",&p,&q,&b);
        for(int j=0;tri(j)<=b;j++)
        {
            int r=rad(b-tri(j));
            if(p+j<=n)
            {
                node *newnode=new node;
                newnode->x=p+j;
                nodeupdate(newnode,max(0,q-r),min(n,q+r));
            }
            if(p-j>=0)
            {
                node *newnode2=new node;
                newnode2->x=p-j;
                nodeupdate(newnode2,max(0,q-r),min(n,q+r));
            }
        }
    }

    for(auto i:myset)
    {
        sort(i->rag.begin(),i->rag.end(),[](pii p,pii q){return p.first<q.first;} );
        int st=0,ed=-1;
        for(auto j:i->rag)
        {
            if(j.first>ed) cnt+=ed-st+1,st=j.first,ed=j.second;
            else ed=max(ed,j.second);
        }
        cnt+=ed-st+1;
    }

    printf("%lld",(long long)(n+1)*(n+1)-(long long)cnt);

    return 0;
}
