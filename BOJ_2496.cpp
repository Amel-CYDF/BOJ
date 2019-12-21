#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

int n,m,t,k,ans_cnt;
pii a[110],ans;

set<pii> myset;

void chk(int x,int y)
{
    int cnt=0;
    for(pii i:myset) if(x<=i.first&&i.first<=x+k&&y<=i.second&&i.second<=y+k) cnt++;
    if(ans_cnt<cnt) ans_cnt=cnt,ans={(k+x+y)/2,(x-y+1)/2};
}

int main(){
    scanf("%d %d %d %d",&n,&m,&t,&k);
    for(int i=0;i<t;i++)
    {
        int x,y;
        scanf("%d %d",&x,&y);
        a[i].first=x+y; a[i].second=x-y;
    }

    sort(a,a+t,[](pii lhs,pii rhs){return lhs.second==rhs.second?lhs.first<rhs.first:lhs.second<rhs.second;});
    int x,y;
    for(int i=0;i<t;i++)
    {
        x=a[i].first,y=a[i].second;
        myset.clear();
        for(int j=i;j<t&&a[j].second<=y+k;j++) myset.insert(a[j]);
        if(myset.size()<=ans_cnt) continue;
        for(pii j:myset)
        {
            x=j.first;
            if(!(x<=a[i].first&&x+k>=a[i].first&&x+k<=2000000)) continue;
            chk(x,y);
        }
    }

    printf("%d %d\n%d",ans.first,ans.second,ans_cnt);

    return 0;
}
