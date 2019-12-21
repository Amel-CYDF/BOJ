#include <bits/stdc++.h>
using namespace std;

int main(){
    //freopen("input.txt","r",stdin);

    int tedt;
    scanf("%d",&tedt);
    while(tedt--)
    {
        int n,ans=0,w=0,b=0; /* b=0, w=1; */
        vector<int> a;
        char c,pre=0;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            int t;
            scanf("%d %c",&t,&c);
            if(c==pre) a[a.size()-1]+=t;
            else a.push_back(t);
            a.size()%2?b+=t:w+=t;
            pre=c;
        }
        if(!b||!w) {printf("%d\n",b+w); continue;}
        int g=__gcd(w,b);
        w/=g; b/=g;
        int bl=0,wi=0;

        for(int i=0;i<a.size();i++)
        {
            if(i%2)
            {
                if(bl&&bl%b==0&&w*(bl/b)>wi&&a[i]>=w*(bl/b)-wi) a[i]-=w*(bl/b)-wi,bl=wi=0,i--,ans++;
                else wi+=a[i];
            }
            else
            {
                if(wi&&wi%w==0&&b*(wi/w)>bl&&a[i]>=b*(wi/w)-bl) a[i]-=b*(wi/w)-bl,bl=wi=0,i--,ans++;
                else bl+=a[i];
            }
        }

        printf("%d\n",ans);
    }
    return 0;
}
