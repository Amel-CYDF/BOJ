#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<pair<int,int>> y_set;
vector<pair<int,int>>x_set;
int Line(vector<pair<int,int>> arr){
    vector<bool> cnt_arr(n+2,false);
    int cnt=0;int ret=0;
    for(int i=0;i<arr.size();++i){
        if(cnt_arr[arr[i].second]==false){
            cnt++;cnt_arr[arr[i].second]=true;
        }
        else{
            cnt--;cnt_arr[arr[i].second]=false;
        }
        if(i==arr.size()-1 || arr[i].first != arr[i+1].first) ret=max(ret,cnt);
    }
    return ret;
}
int main(){
    cin>>n;
    int pre_x,pre_y;
    cin>>pre_x>>pre_y;
    int st_x=pre_x, st_y=pre_y;
    for(int i=1;i<n;++i){
        int x,y;cin>>x>>y;
        if(pre_y!=y){
            y_set.push_back({pre_y,i});
            y_set.push_back({y,i});
        }
        if(pre_x!=x){
            x_set.push_back({pre_x,i});
            x_set.push_back({x,i});
        }
        pre_x=x;
        pre_y=y;
    }
    if(pre_y!=st_y){
        y_set.push_back({pre_y,n});
        y_set.push_back({st_y,n});
    }
    if(pre_x!=st_x){
        x_set.push_back({pre_x,n});
        x_set.push_back({st_x,n});
    }
    sort(y_set.begin(), y_set.end());
    sort(x_set.begin(), x_set.end());
//    for(int i=0;i<x_set.size();++i){
//        cout<<x_set[i].first<<" "<<x_set[i].second<<endl;
//    }
//    for(int i=0;i<y_set.size();++i){
//        cout<<y_set[i].first<<" "<<y_set[i].second<<endl;
//    }
    cout<<max(Line(y_set),Line(x_set))<<"\n";
}
