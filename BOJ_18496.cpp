#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define MOD 1000000007

struct node
{
	bitset<700> a;
	int siz;

	node(int mysiz=0){a.reset(); siz=mysiz;}

	bool operator<(const node &p)const
	{
		if(siz!=p.siz) return siz<p.siz;
		for(int i=siz;i--;)
			if(a[i]!=p.a[i]) return p.a[i];
		return false;
	}
	node operator+(const node &p)const
	{
		bool car=false;
		int r=max(siz,p.siz);
		node ret;
		for(int i=0;i<r;i++)
			ret.a[i]=a[i]^p.a[i]^car,
			car=(car&(!ret.a[i]))|(a[i]&p.a[i]);
		if(car) ret.a.set(r),r++;
		ret.siz=r;
		return ret;
	}
	node operator-(const node &p)const
	{
		bool bor=false;
		node ret(siz);
		for(int i=0;i<siz;i++)
			ret.a[i]=a[i]^p.a[i]^bor,
			bor=((bor^p.a[i])&(!a[i]))|(bor&p.a[i]);
		assert(!bor);
		while(ret.siz&&!ret.a.test(ret.siz-1)) ret.siz--;
		return ret;
	}
	node operator*(const node &p)const
	{
		if(!p.siz) return p;
		node ret;
		for(int i=siz;i--;)
			if(a.test(i))
			{
				node tmp=p;
				tmp.a<<=i; tmp.siz+=i;
				ret=ret+tmp;
			}
		return ret;
	}
	node mydiv(const node &p, bool isdiv)const
	{
		if(siz<p.siz) {node tmp; return isdiv?tmp:*this;}
		node ret(siz-p.siz+1),w=*this;
		for(int i=siz-p.siz+1;i--;)
		{
			node tmp=p;
			tmp.a<<=i; tmp.siz+=i;
			if(!(w<tmp))
			{
				w=w-tmp;
				ret.a.set(i);
			}
		}
		if(!isdiv) return w;
		while(ret.siz&&!ret.a.test(ret.siz-1)) ret.siz--;
		return ret;
	}
	node operator/(const node &p)const
	{
		return mydiv(p,true);
	}
	node operator%(const node &p)const
	{
		return mydiv(p,false);
	}
};

int n,m;

node ten(4);
void dec2bin(node &p)
{
	string a;
	cin>>a;
	node t(1); t.a.set(0);
	for(int i=a.size();i--;)
	{
		node tmp;
		for(int j=a[i]-'0';j;j>>=1)
			tmp.a[tmp.siz++]=j&1;
		p=p+(tmp*t);
		t=t*ten;
	}
}

void bin2dec(node p)
{
	string a;
	for(node tmp;p.siz;)
	{
		tmp=p%ten;
		int ret=0;
		for(int i=0;i<tmp.siz;i++)
			if(tmp.a.test(i)) ret^=1<<i;
		a.pb(ret+'0');
		p=p/ten;
	}
	reverse(a.begin(),a.end());
	cout<<a<<'\n';
}

node gcd(node p,node q)
{
	if(!q.siz) return p;
	return gcd(q, p%q);
}

void Solve()
{
	ten.a.set(1); ten.a.set(3);

	node d,k;
	dec2bin(d); dec2bin(k);
	node ans=d;
	if(!d.a[0] && d.a[1] && !k.a[0] && k.siz>2)
		ans.a<<=1, ans.siz++;
	for(;;)
	{
		node p=gcd(k,d);
		if(p.siz==1) break;
		for(node tmp;;)
		{
			ans=ans*p;
			k=k/p;
			tmp=k%p;
			if(tmp.siz) break;
		}
	}
	bin2dec(ans);
}

void Init(bool isLocal){ if(isLocal) freopen("input.txt","r",stdin);
//	ios::sync_with_stdio(false); cin.tie(NULL);
}
int main(){ Init(01);
//    int tc; cin>>tc; while(tc--)
    Solve();
    return 0;
}
