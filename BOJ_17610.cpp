#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
vector<int> vector2;
vector<int> result;
int cnt=0;int n;
void Solve(int sum, int now){
    if(now==n){
        if(sum>0 && result[sum]!=1){
            result[sum]=1;
            cnt++;
        }
        return;
    }
    Solve(sum+vector2[now],now+1);
    Solve(sum,now+1);
    Solve(sum-vector2[now],now+1);
}
int main(){
    cin>>n;
    int S=0;
    for(int i=0;i<n;++i){
        int a; cin>>a;
        S+=a;
        vector2.push_back(a);
    }
    result.resize(S+1);
    Solve(0,0);
    cout<<S-cnt<<"\n";
}
