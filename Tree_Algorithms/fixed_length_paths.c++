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
int n,k,maxd;
lli ans=0;
vector<vector<int>> edge;
vector<lli> ss,freq;
vector<bool> mark;
 
int dfs(int node,int p)
{
	ss[node]=1;
	for(int &i:edge[node])
	{
		if(i==p || mark[i]) continue;
		ss[node]+=dfs(i,node);
	}
	return ss[node];
}
 
int get_cent(int node,int sts,int p)
{
	for(int &i:edge[node])
	{
		if(i==p || mark[i]) continue;
		if(2*ss[i]>sts) return get_cent(i,sts,node);
	}
	return node;
}
 
void dfs_calc(int node,int p,int fill,int depth)
{
	if(depth==k && !fill) ans++;
	if(depth>=k) return;
	if(fill) freq[depth]++;
	else ans+=freq[k-depth];
	maxd=max(maxd,depth);
	for(int &i:edge[node])
	{
		if(mark[i] || i==p) continue;
		dfs_calc(i,node,fill,depth+1);
	}
}
 
void cent_tree(int node=1,int p=0)
{
	int C=get_cent(node,dfs(node,0),p);
	mark[C]=true;
    maxd=0;
	for(int &i:edge[C]) 
	{
		if(mark[i]) continue;
		dfs_calc(i,C,false,1);		///calculating parts prior to activation of current subtree
		dfs_calc(i,C,true,1);		// activating the current subtree
	}
 
	//the two dfs cannot be done together as there will be ans from same subtree which may be incorrect
	// we are only looking for k paths within a subtree rooted at centroid C
 
	fill(freq.begin(),freq.begin()+maxd+1,0);
	for(int &i:edge[C])
	{
		if(mark[i]) continue;
		cent_tree(i,C);
	}
}
 
 
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout<< std::fixed;
    std::cout.precision(6);
    
	cin>>n>>k;
	edge=vector<vector<int>> (n+1);
	ss=vector<lli> (n+1,0);
	freq=vector<lli> (k+10,0);
	mark=vector<bool> (n+1,false);
 
	forr(i,1,n) 
	{
		int a,b;
		cin>>a>>b;
		edge[a].eb(b);
		edge[b].eb(a);
	}
 
	cent_tree();
	cout<<ans<<"\n";
		
 
	return 0;
}


// from a centroid C(rooted)  look into its subtree to find paths of length k
