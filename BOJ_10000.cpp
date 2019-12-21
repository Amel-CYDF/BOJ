#include <bits/stdc++.h>
using namespace std;

int n,ans;
struct circle
{
    int x,r,lf,rg,mid;
}a[300010];

stack<circle*> st;

void stpop()
{
    int toplf=st.top()->lf,toprg=st.top()->rg;
    if(st.top()->mid==toprg) ans++;
    st.pop();
    if(!st.empty()&&st.top()->mid==toplf) st.top()->mid=toprg;
}

int main(){
    scanf("%d",&n); ans=n+1;
    for(int i=0;i<n;i++) scanf("%d %d",&a[i].x,&a[i].r),a[i].lf=a[i].mid=a[i].x-a[i].r,a[i].rg=a[i].x+a[i].r;
    sort(a,a+n,[](circle lhs,circle rhs){return lhs.lf==rhs.lf?lhs.rg>rhs.rg:lhs.lf<rhs.lf;});


    for(int i=0;i<n;i++)
    {
        while(!st.empty()&&st.top()->rg<=a[i].lf) stpop();
        st.push(a+i);
    }

    while(!st.empty()) stpop();

    printf("%d",ans);
    return 0;
}
