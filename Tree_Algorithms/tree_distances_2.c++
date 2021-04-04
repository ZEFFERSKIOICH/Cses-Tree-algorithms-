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
 
lli n,dist;
 
vector<vector<int>> edge;
vector<lli> ss,ans;
void dfs(int node,int p,lli lvl)
{
	dist+=lvl++;
	ss[node]=1;
	for(int &i:edge[node])
	{
		if(i==p) continue;
		dfs(i,node,lvl);
		ss[node]+=ss[i];
	}
}
 
void dfs1(int node,int p)
{
	for(int &i:edge[node]) 
	{
		if(i==p) continue;
		ans[i]=ans[node]-ss[i]+n-ss[i];
		dfs1(i,node);
	}
}
 
 
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout<< std::fixed;
    std::cout.precision(6);
	
	cin>>n;
	edge=vector<vector<int>> (n+1);
	ans=ss=vector<lli> (n+1,0);
	forr(i,1,n){int a,b;cin>>a>>b;edge[a].eb(b);edge[b].eb(a);}
	dfs(1,1,0);
	ans[1]=dist;
	dfs1(1,1);
	forr(i,1,n+1) cout<<ans[i]<<" ";
	return 0;
}

//only key observation : if(n) is the node  currently rooted then distance of all nodes in the subtree reduces by 1 
//						 and all other distance to all other nodes increases by 1
