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
vector<int> v;
vector<int> ans;
vector<set<int>> s;
void dfs(int node=1,int p=0)
{
	for(int &i:edge[node])
	{
		if(i==p) continue;
		dfs(i,node);
		if(s[node].size()<s[i].size()) swap(s[node],s[i]);
		s[node].insert(s[i].begin(),s[i].end());
	}
	s[node].insert(v[node-1]);
	ans[node]=s[node].size();
}
 
 
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout<< std::fixed;
    std::cout.precision(6);
    
 	cin>>n;
	edge=vector<vector<int>> (n+1);
	ans=v=vector<int> (n+1,0);
	s=vector<set<int>> (n+1);
	forr(i,0,n) cin>>v[i];
 
	forr(i,1,n)		{int a,b;cin>>a>>b;edge[a].eb(b);edge[b].eb(a);}
	dfs();
 
	forr(i,1,n+1) cout<<ans[i]<<" ";cout<<"\n";
    
    
 
    return 0;
}

//simple small to large merging

