#pragma warning(disable:4996)
#include<stdio.h>
#define N 1000009
#define Q 100009
typedef long long int ll;
int n, q, a[N], b[N], S[N], num[N];
ll suma[N], sumb[N];
char inp[N];
void no_stone();//바위가 없는 경우
void stone();//바위가 있는 경우
ll sum_a(int s, int e);
ll sum_b(int s, int e);
int binary_search_a(int s, int e, int l);
int binary_search_STONE(int s, int e, int l);
int binary_search_b(int s, int e, int l);

int main() {
	scanf("%d%d", &n, &q);
	scanf("%s", &inp[1]);
	int i, stone_check = 0;
	for (i = 1; i <= n; i++) {
		if (inp[i] == 'R') {
			stone_check = 1;
		}
	}
	if (stone_check == 0) {
		no_stone();
	}
	else {
		stone();
	}
}
void no_stone() {
	int i, k = 0;
	a[0] = 0;
	for (i = 1; i <= n; i++) {
		if (inp[i] == 'P') {
			a[++k] = i;
		}
	}
	a[k + 1] = n + 1;
	suma[0] = (0ll);
	for (i = 1; i <= (n + 1); i++) {
		suma[i] = suma[i - 1] + ((ll)a[i]);
	}
	for (i = 1; i <= q; i++) {
		int l;
		scanf("%d", &l);
		ll anspot;
		int s = binary_search_a(0, k + 1, l);
		if ((2 * s) < k) {
			anspot = (2ll)*(sum_a(s + 1, 2 * s + 1) - sum_a(1, s)) - ((ll)l) - (0ll);
			printf("%d %lld\n", 2 * s + 1, anspot);
		}
		else {
			anspot = (2ll)*(sum_a(s + 1, k) - sum_a(2 * s + 1 - k, s)) + ((ll)(n + 1)) - ((ll)l);
			printf("%d %lld\n", 2 * (k - s), anspot);
		}
	}
}
void stone() {
	int i, j, stone_num = 0, k1 = 0, k2 = 0;
	for (i = 1; i <= n; i++) {
		if (inp[i] == 'R') {
			S[++stone_num] = i;
		}
	}
	S[0] = 0, S[stone_num + 1] = n + 1;
	for (i = 0; i <= stone_num; i++) {
		for (j = S[i] + 1; j < S[i + 1]; j++) {
			if (inp[j] == 'P') {
				++num[i];
			}
		}
	}
	a[0] = 0;
	for (i = 1; i < S[1]; i++) {
		if (inp[i] == 'P') {
			a[++k1] = i;
		}
	}
	a[k1 + 1] = n + 1;
	b[0] = 0;
	for (i = S[stone_num]; i <= n; i++) {
		if (inp[i] == 'P') {
			b[++k2] = i;
		}
	}
	b[k2 + 1] = n + 1;
	suma[0] = (0ll);
	for (i = 1; i <= (k1 + 1); i++) {
		suma[i] = suma[i - 1] + ((ll)a[i]);
	}
	sumb[0] = (0ll);
	for (i = 1; i <= (k2 + 1); i++) {
		sumb[i] = sumb[i - 1] + ((ll)b[i]);
	}
	for (i = 1; i <= q; i++) {
		int l;
		scanf("%d", &l);
		ll anspot;
		if (l < S[1]) {
			int s = binary_search_a(0, k1 + 1, l);
			if (s < (k1 - s)) {
				anspot = (2ll)*(sum_a(s + 1, 2 * s + 1) - sum_a(1, s)) - ((ll)l) - (0ll);
				printf("%d %lld\n", 2 * s + 1, anspot);
			}
			else {
				anspot = (2ll)*(sum_a(s + 1, k1) - sum_a(1, s)) - ((ll)l) - (0ll) + (2ll)*((ll)(2 * s - k1 + 1))*((ll)S[1]);
				printf("%d %lld\n", k1, anspot);
			}
		}
		else if (S[stone_num] < l) {
			int s = binary_search_b(0, k2 + 1, l);
			if (s < (k2 - s)) {
				anspot = (2ll)*(sum_b(s + 1, k2) - sum_b(1, s)) - ((ll)l) + ((ll)(n + 1)) - (2ll)*((ll)(k2 - 2 * s))*((ll)S[stone_num]);
				printf("%d %lld\n", k2, anspot);
			}
			else {
				anspot = (2ll)*(sum_b(s + 1, k2) - sum_b(2 * s - k2 + 1, s)) - ((ll)l) + ((ll)(n + 1));
				printf("%d %lld\n", 2 * (k2 - s), anspot);
			}
		}
		else {
			int s = binary_search_STONE(0, stone_num + 1, l);
			printf("%d -1\n", num[s]);
		}
	}
}
ll sum_a(int s, int e) {
	if (s > e) {
		return (0ll);
	}
	return (suma[e] - suma[s - 1]);
}
ll sum_b(int s, int e) {
	if (s > e) {
		return (0ll);
	}
	return (sumb[e] - sumb[s - 1]);
}
int binary_search_a(int s, int e, int l) {
	int m;
	for (;;) {
		m = (s + e) / 2;
		if ((s + 1) == e) {
			return s;
		}
		if (a[m] < l) {
			s = m;
		}
		else {//l < a[m]
			e = m;
		}
	}
}
int binary_search_STONE(int s, int e, int l) {
	int m;
	for (;;) {
		m = (s + e) / 2;
		if ((s + 1) == e) {
			return s;
		}
		if (S[m] < l) {
			s = m;
		}
		else {//l < S[m]
			e = m;
		}
	}
}
int binary_search_b(int s, int e, int l) {
	int m;
	for (;;) {
		m = (s + e) / 2;
		if ((s + 1) == e) {
			return s;
		}
		if (b[m] < l) {
			s = m;
		}
		else {//l < b[m]
			e = m;
		}
	}
}
