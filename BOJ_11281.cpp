#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<vpii> vvpii;
typedef vector<vpll> vvpll;
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define MOD 1'000'000'007

int n,m;

const int N = 2'0'010;
vector<vector<int>> ed;
int up[N], vis[N], vtime;

vector<int> stk;
int scc_idx[N], scc_cnt;

void dfs(int p) {
	up[p] = vis[p] = vtime++;
	stk.push_back(p);

	for(auto i: ed[p]) {
		if(!~vis[i]) {
			dfs(i);
			up[p] = min(up[p], up[i]);
		}
		else if(!~scc_idx[i])
			up[p] = min(up[p], vis[i]);
	}

	if(up[p] == vis[p]) {
		for(int i = -1; !stk.empty() && i != p; ) {
			i = stk.back();
			stk.pop_back();
			scc_idx[i] = scc_cnt;
		}
		scc_cnt++;
	}
}

// Vertex Number [s, e] --> scc_idx = 0 ~ scc_cnt-1;
// the order of scc_idx constitutes a reverse topological sort
void scc(int s, int e) {
	vtime = scc_cnt = 0;
	memset(vis, -1, sizeof(vis));
	memset(scc_idx, -1, sizeof(scc_idx));
	stk.clear();
	for(; s <= e; s++)
		if(!~vis[s]) dfs(s);
}

// Add after SCC code (change array size to [2 * N + 10])
int satn;
void satinit(int p) { ed.resize(N); satn = p; }

// denote positive variables 0 ~ N - 1, negative variables N ~ 2N - 1
int NOT(int p) {
	return p < satn ? (p + satn) : (p - satn);
}

// make edge of p OR q ; input ~x to denote NOT
void addedge(int p, int q) {
	if(p >> 31 & 1) p = ~p + satn;
	if(q >> 31 & 1) q = ~q + satn;
	ed[NOT(p)].pb(q); ed[NOT(q)].pb(p);
}

bool sat(int p, vector<bool> &res /* OR bool res[] */) {
	satn = p;
	res.resize(p);	// REMOVE if using array
	scc(0, 2 * p - 1);
	for(int i = p; i--; ) {
		if(scc_idx[i] == scc_idx[NOT(i)]) return false;
		if(scc_idx[i] < scc_idx[NOT(i)]) res[i] = true;
		else res[i] = false;
	}
	return true;
}

void Solve()
{
	cin>>n>>m;
	satinit(n);
	for(int i,j; m--; )
	{
		cin>>i>>j;
		if(i>0) i--;
		if(j>0) j--;
		addedge(i,j);
	}
	vector<bool> res;
	if(!sat(n,res)) {cout<<0; return;}
	cout<<"1\n";
	for(auto i: res) cout<<i<<' ';
}

void Init(bool isLocal){ if(isLocal) freopen("input.txt","r",stdin);
	ios::sync_with_stdio(false); cin.tie(NULL);
}
int main(){ Init(0);
//	int tc; cin>>tc; for(int i=1;i<=tc;i++)
//	cout<<"Case #"<<i<<'\n',
	Solve();
	return 0;
}

