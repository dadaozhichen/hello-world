#include<bits/stdc++.h>
using namespace std;
const int N=300+10;
typedef pair<int,int> PII;
#define x first
#define y second
 
int T,l,n,m;
int a[N];
vector<PII> vec[N];
int f[N][N][N],g[N][N];

int read()
{
	int l=1,w=0;
	char c=getchar();
	while(c<'0'||c>'9') {
		if(c=='-') l=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		w=w*10+(c-'0');
		c=getchar();
	}
	return w*l;
}
bool dfs(int u,int v,int k)
{
	bool win=true;
	if(f[u][v][k]!=-1) return f[u][v][k];
	if(k==l) return true;
	for(auto t : vec[a[k+1]])
	{
		if(t.x>u&&t.y>v){
			if(dfs(t.x,t.y,k+1)) win=false;
		}
	}
	f[u][v][k]=win;
	return f[u][v][k];
}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&l,&n,&m);
		for(int i=1;i<=n+1;i++)
			for(int j=1;j<=m+1;j++)
			{
				for(int k=1;k<=l+1;k++) 
					f[i][j][k]=-1; 
			}
				
		for(int i=1;i<=l;i++) a[i]=read();
		
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
			{
				g[i][j]=read();
				while(vec[g[i][j]].size()&&vec[g[i][j]].back().y<j) vec[g[i][j]].pop_back();
				vec[g[i][j]].push_back({i,j}); 
 			}
 		bool flag=false;
 		for(auto t:vec[a[1]])
 		{
 			bool ans=dfs(t.x,t.y,1);
 			if(ans==true) {
 				flag=true;break;
			 }	 
		}
		if(flag==true) cout<<"T"<<endl;
		else cout<<"N"<<endl;
		
		for(int i=1;i<=n+1;i++)
			for(int j=1;j<=m+1;j++)
			{
				vec[g[i][j]].clear();
			}
	}
	return 0;
}
