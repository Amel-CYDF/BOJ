#include <bits/stdc++.h>
using namespace std;

int n,a[5010][3];
pair<int,int> ans;
int x[10]={0,-1,0,1,1,1,0,-1,-1},y[10]={0,1,1,1,0,-1,-1,-1,0};

int meet(int p,int q)
{
    int vx=x[a[p][2]]-x[a[q][2]], vy=y[a[p][2]]-y[a[q][2]];
    int dx=a[q][0]-a[p][0], dy=a[q][1]-a[p][1];
    if(!dx&&!vx&&vy&&dy%vy==0&&dy/vy>0) return dy/vy;
    if(!dy&&!vy&&vx&&dx%vx==0&&dx/vx>0) return dx/vx;
    if(!vx||!vy) return 0;
    if(dx%vx==0&&dy%vy==0&&dx/vx==dy/vy&&dx/vx>0) return dx/vx;
    return 0;
}


int main(){
  //  freopen("input.txt","r",stdin);

    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d %d %d",&a[i][0],&a[i][1],&a[i][2]);

    for(int i=0;i<n;i++)
    {
        int b[5010],cnt=0;
        for(int j=0;j<n;j++)
            if(i!=j&&meet(i,j)) b[cnt++]=meet(i,j);
        sort(b,b+cnt);
        b[cnt]=INT_MAX;
        int now=0,num=0;
        for(int i=0;i<=cnt;i++,num++)
            if(now!=b[i])
            {
                if(ans.second<num||(ans.second==num&&ans.first>now)) ans={now,num};
                num=0; now=b[i];
            }
    }

    printf("%d\n%d",ans.second+1,ans.first);

    return 0;
}
