#include <bits/stdc++.h>
using namespace std;

int n;
bitset<60'001> a,b,ans;
vector<int> c;

int main()
{
	cin>>n;
	for(int i;n--;)
	{
		cin>>i;
		a.set(i+30'000);
	}
	cin>>n;
	c.resize(n);
	for(auto &i:c) cin>>i, i+=30'000;

	cin>>n;
	for(int i;n--;)
	{
		cin>>i;
		b.set(30'000-i);
	}

	long long cnt=0;
	for(auto &i:c)
	{
		i=60'000 - i*2;
		if(i>0)
			ans = (a << i) & b;
		else
			ans = (a >> (-i)) & b;
		cnt += ans.count();
	}

	cout<<cnt;

    return 0;
}
