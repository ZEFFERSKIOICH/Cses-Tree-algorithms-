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
vector<int> depth;
vector<vector<int>> edge;
void dfs(int node,int p,int lvl)
{
	depth[node]=lvl++;
	for(int &i:edge[node])
	{
		if(i==p) continue;
		dfs(i,node,lvl);
	}
}
 
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout<< std::fixed;
    std::cout.precision(6);
   	
	cin>>n;
	depth=vector<int> (n+1,0);
	edge=vector<vector<int>> (n+1);
	forr(i,1,n)
	{
		int a,b;cin>>a>>b;
		edge[a].eb(b);
		edge[b].eb(a);
	}
	dfs(1,1,0);
	int maxi=0,pos=0;
	forr(i,1,n+1) 
	{
		if(maxi<depth[i]) {maxi=depth[i];pos=i;}
	}
	dfs(pos,pos,0);
	maxi=0;
	forr(i,1,n+1)
	{
		maxi=max(maxi,depth[i]);
	}
	cout<<maxi<<"\n";
	
 
	return 0;
}
