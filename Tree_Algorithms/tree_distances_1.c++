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
 
int n,l;
vector<vector<int>> edge,lift;
vector<int> tin,tout,depth;
int timer=0;
void dfs(int node,int p,int lvl=0)
{
	tin[node]=++timer;
	depth[node]=lvl++;
	lift[node][0]=p;
	for(int i=1;i<=l;i++)
	{
		lift[node][i]=lift[lift[node][i-1]][i-1];
	}
	for(int &i:edge[node])
	{
		if(i==p) continue;
		dfs(i,node,lvl);
	}
	tout[node]=++timer;
}
 
 
inline bool is_anc(int u,int v) {return tin[u]<tin[v] && tout[u]>tout[v];}
 
int lca(int u,int v)
{
	if(is_anc(u,v))	return u;
	if(is_anc(v,u))	return v;
	
	for(int i=l;i>=0;i--)
	{
		if(!(is_anc(lift[u][i],v)))	{u=lift[u][i];}
	}
	return lift[u][0];
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout<< std::fixed;
    std::cout.precision(6);
   	
	cin>>n;
	l=ceil((double)log(n)/log(2));
	edge=vector<vector<int>> (n+1);
	lift=vector<vector<int>> (n+1,vector<int> (l+1,0));
	depth=tin=tout=vector<int> (n+1,0);
	forr(i,0,n-1)
	{
		int a,b;
		cin>>a>>b;
		edge[a].eb(b);
		edge[b].eb(a);
	}
	dfs(1,1);
	int maxi=0;
	int pos=0,pos1=0;
	forr(i,1,n+1)
	{
		if(maxi<depth[i]) {maxi=depth[i],pos=i;}
	}
	dfs(pos,pos);
	int maxi2=0;
	forr(i,1,n+1) {if(maxi2<depth[i])	{maxi2=depth[i];pos1=i;}}
	forr(i,1,n+1)
	{	
		if(pos1==i) {cout<<depth[i]<<" ";continue;}
		int node=lca(i,pos1);
		cout<<max(depth[i],-depth[node]*2+depth[i]+depth[pos1])<<" ";
	}
 
 
 
	return 0;
}

//only key ovservation is that max distance from a node will be to either of the two ends of the diameter


