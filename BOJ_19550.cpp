#include <stdio.h>
#include <algorithm>

using namespace std;

struct se{
	int s, e;
};

bool comp_e(const se x, const se y)
{
	return x.e < y.e;
}

int n, l, k;
se band[100000];

se SE(int s, int e)
{
	int x, y;
	se tmp;
	
	x = min(s, e);
	y = max(s, e);
	
	if(y-x > x-y+l){
		tmp.s = y-l;
		tmp.e = x;
	}
	else{
		tmp.s = x;
		tmp.e = y;
	}
	
	return tmp;
}

int cycle()
{
	int cnt=0, i;
	
	sort(band, band+n, comp_e);
	
	k -= l;
	for(i=0; i<n; i++){
		if(band[i].s <= k) continue;
		
		k = band[i].e;
		cnt++;
	}
	
	for(i=0; i<n; i++){
		if(band[i].s+l <= k){
			band[i].s += l;
			band[i].e += l;
		}
	}
	
	return cnt;
}

int main()
{
	int i, s, e, ans, tmp;
	
	scanf("%d %d", &n, &l);
	for(i=0; i<n; i++){
		scanf("%d %d", &s, &e);
		band[i] = SE(s,e);
	}
	
	ans = n;
	
	for(i=0; i<2; i++){
        tmp = cycle();
		ans = min(ans, tmp);
	}
	
	printf("%d", ans);
	
	return 0;
}