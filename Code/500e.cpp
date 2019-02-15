#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e5+7;
int p[MAXN],l[MAXN],x[MAXN],dp[MAXN][30];

int32_t main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>p[i]>>l[i];
		l[i]+=p[i];
	}
	
	stack<int>S;
    for(int i=n;i>=1;i--)
	{
		while( S.size() && l[S.top()] < l[i])
			S.pop();
		
        int a=( S.size() ? S.top() : 0 );
        dp[i][0]=a;
        x[i]=x[a]+max(0, p[a]-l[i] );
		
		for(int j=1;j<20;j++)
            dp[i][j]=dp[ dp[i][j-1] ][j-1];
		
		S.push(i);
    }
	
	int q;
	cin>>q;
	while(q--)
	{
		int s,e;
		cin>>s>>e;
        if(l[s]>=p[e])
            cout<<"0\n";
        else
        {
            int a=s;
			for(int i=20;i>=0;i--)
			{
				int temp=dp[a][i];
                if(l[temp]<p[e]&&temp!=0)
                    a=temp;
            }
            cout<<x[s]-x[dp[a][0]]<<'\n';
        }
    }
}