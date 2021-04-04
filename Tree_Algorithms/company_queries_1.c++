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
 
int n,q,l;
vector<vector<int>> edge;
vector<vector<int>> lift;
vector<int> tin,tout,depth;
int timer=0;
void dfs(int node=1,int p=1,int lvl=0)
{
	tin[node]=++timer;
	depth[node]=lvl++;
	lift[node][0]=p;
	for(int i=1;i<=l;i++)	lift[node][i]=lift[lift[node][i-1]][i-1];
 
	for(int &i:edge[node]) 
	{
		if(i==p) continue;
		dfs(i,node,lvl);
	}
	tout[node]=++timer;
}
 
int findlvl(int node,int lvl)
{
	int ans=node;
	for(int i=30;i>=0;i--)
	{
		if(lvl&(1<<i)) ans=lift[ans][i];
	}
	return ans;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout<< std::fixed;
    std::cout.precision(6);
	
	cin>>n>>q;
	l=ceil((double)log(n)/log(2))+1;
	depth=tin=tout=vector<int> (n+1,0);
	lift=vector<vector<int>> (n+1,vector<int> (l,0));
	edge=vector<vector<int>> (n+1);
	forr(i,2,n+1)
	{
		int a;cin>>a;edge[i].eb(a);edge[a].eb(i);
	}
	dfs();
	while(q--)
	{
		int node,lvl;
		cin>>node>>lvl;
		if(lvl<=depth[node]) 	cout<<findlvl(node,lvl)<<"\n";
		else cout<<"-1\n";
	}
 
 
	return 0;
}
 
 
 
 
//simple application of binary lifting  
 
