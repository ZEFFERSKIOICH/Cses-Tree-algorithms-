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
 
int n,ans;
vector<vector<int>> edge;
vector<bool>match;
vector<int> dp1,dp2;
 
void dfs(int node,int p)
{
	for(int &i:edge[node]) 
	{
		if(i==p) continue;
		dfs(i,node);
	}
 
	for(int &i:edge[node]) {if(i==p) continue; dp2[node]+=max(dp1[i],dp2[i]);}
	for(int &i:edge[node]) 
	{
		if(i==p) continue;
		dp1[node]=max(dp1[node],1+dp2[i]+dp2[node]-max(dp1[i],dp2[i]));
	}
}
 
//dp1 : an edge to immediate child exists
//dp2 : edge to immediate child does not exists 
 
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout<< std::fixed;
    std::cout.precision(6);
	
	cin>>n;
	edge=vector<vector<int>> (n+1);
	match=vector<bool>(n+1,false);
	dp1=dp2=vector<int> (n+1,0);
	forr(i,1,n){int a,b;cin>>a>>b;edge[a].eb(b);edge[b].eb(a);}
	dfs(1,1);
	cout<<max(dp1[1],dp2[1])<<"\n";
	return 0;
}
 
 
 
 
 
 
 
