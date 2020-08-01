#include<stdio.h>
#include<vector>
using namespace std;
#define N 100009
int n, s, d, hgt[N], mxx[N], ans;
vector<int> node[N];
int dfs(int s, int height) {
	int mx = 0;
	hgt[s] = height;
	for (int next : node[s]) {
		if (hgt[next] != 0) {
			continue;
		}
		int imsi = dfs(next, height + 1);
		if (mx < imsi) {
			mx = imsi;
		}
	}
	++mx;
	mxx[s] = mx;
	if (mx <= d) {
		++ans;
	}
	return mx;
}
int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d%d%d", &n, &s, &d);
	int i, j;
	for (i = 1; i < n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		node[x].push_back(y);
		node[y].push_back(x);
	}
	
	dfs(s, 1);
	int imsiss = 2 * (n - ans - 1);
	if (imsiss < 0) {
		imsiss = 0;
	}
	printf("%d", imsiss);
}