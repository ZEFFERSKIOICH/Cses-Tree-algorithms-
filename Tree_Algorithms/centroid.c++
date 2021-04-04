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
int n;
vector<vector<int>> edge;
vector<int> ss;
int dfs(int node=1,int p=0)
{
	ss[node]=1;
	for(int &i:edge[node])
	{
		if(i==p) continue;
		ss[node]+=dfs(i,node);
	}
	return ss[node];
}
 
 
int get_c(int node,int p,int sts)
{	
	for(int &i:edge[node])
	{
		if(i==p) continue;
		if(ss[i]*2>sts)
		{
			return get_c(i,node,sts);
		}
	}
	return node;
}
 
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout<< std::fixed;
    std::cout.precision(6);
    
  	cin>>n; 
	edge=vector<vector<int>> (n+1);
	ss=vector<int> (n+1,0);
	forr(i,1,n)
	{
		int a,b;cin>>a>>b;
		edge[a].eb(b);edge[b].eb(a);
	}
	cout<<get_c(1,0,dfs())<<"\n";
    
    
    
 
    return 0;
}
 
 
 
 
 
// code inspired by a usaco post  
