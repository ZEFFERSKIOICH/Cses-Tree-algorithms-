// coded by zeffy
#pragma GCC optimize("O3","unroll-loops","omit-frame-pointer","inline") //Optimization flags
#pragma GCC option("arch=native","tune=native","no-zeroupper") //Enable AVX
#pragma GCC target("avx","popcnt")  //Enable AVX
#include <x86intrin.h> //SSE Extensions
#include <bits/stdc++.h> 
using namespace std;
#define eb emplace_back
#define mp make_pair
#define hello cout<<"hello"<<"\n"
#define forr(i,a,b) for(int i=a;i<b;i++)
#define it(s)	for(auto itr:s)
#define dvg(s) 	for(auto itr:s)	cout<<itr<<" ";cout<<endl;
#define dbg(s)	cout<<#s<<"= "<<s<<endl;
typedef long long int lli;
typedef unsigned long long int ulli;
const lli INF=(lli)1e17+5;
const ulli MOD=1e9+7;
 
int n,q;
vector<vector<int>> edge;
int timer=0;
vector<lli> seg,v;
vector<int>tin,tout;
void dfs(int node=1,int p=1,int lvl=0)
{
	tin[node]=timer++;
	for(int &i:edge[node]) 
	{
		if(i==p) continue;
		dfs(i,node,lvl);
	}
	tout[node]=timer-1;
}
 
void build()
{
	forr(i,0,n) {seg[tin[i+1]+n+1]+=v[i];seg[tout[i+1]+1+n+1]-=v[i];}
	for(int i=n;i>0;i--) seg[i]=seg[i<<1]+seg[i<<1|1];
}
 
void update(int pos,lli val)
{
	pos+=n+1;
	seg[pos]+=val;
	for(int i=pos;i>1;i=i>>1) seg[i>>1]=seg[i]+seg[i^1];
}
 
lli query(int l,int r)
{
	l+=n+1;r+=n+1;
	lli sum=0;
	while(l<=r)
	{
		if(l&1) sum+=seg[l++];
		if(!(r&1)) sum+=seg[r--];
		l=l>>1;r=r>>1;
	}
	return sum;
}
 
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout<< std::fixed;
    std::cout.precision(6);
	
	cin>>n>>q;
	tin=tout=vector<int> (n+1,0);
	seg=vector<lli> (2*n+2,0);
	v=vector<lli> (n,0);
	forr(i,0,n) cin>>v[i];
	edge=vector<vector<int>> (n+1);
	forr(i,1,n)
	{
		int a,b;cin>>a>>b;edge[a].eb(b);edge[b].eb(a);
	}
	dfs();
	build();
	while(q--)
	{
		int ch;
		cin>>ch;
		if(ch==1)
		{
			lli node,val;
			cin>>node>>val;
			lli send=val-v[node-1];
			v[node-1]=val;
			update(tin[node],send);
			update(tout[node]+1,-send);
			
		}
		else 
		{
			int node;
			cin>>node;
			cout<<query(0,tin[node])<<"\n";
		}
	}
 
 
 
 
	return 0;
}
 
 
 
 
