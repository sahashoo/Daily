#include<bits/stdc++.h>
// #define int long long
using namespace std;
const int MAXN=5e5+7;
vector<int>vec[MAXN],g[MAXN];
set<int>Sv,a;
queue<int>Q;
int ind;

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
		Sv.insert(i);
	for(int i=0;i<m;i++)
	{
		int u,v;
		scanf("%d %d",&v,&u);
		g[v].push_back(u);
		g[u].push_back(v);
	}
	
	
	while(Sv.size())
	{
		ind++;
		int v=*Sv.begin();
		Q.push(v);
		Sv.erase(v);
		
		while(Q.size())
		{
			v=Q.front();
			Q.pop();
			vec[ind].push_back(v);
			
			for(int u:g[v])
				if(Sv.find(u)!=Sv.end())
				{
					a.insert(u);
					Sv.erase(u);
				}
			
			while(Sv.size())
			{
				Q.push(*Sv.begin());
				Sv.erase(Sv.begin());
			}
			Sv.swap(a);
		}
	}
	
	cout<<ind<<'\n';
	for(int i=1;i<=ind;i++)
	{
		cout<<vec[i].size()<<" ";
		for(int x:vec[i])cout<<x<<" ";
		cout<<'\n';
	}
}