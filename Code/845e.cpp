#include<bits/stdc++.h>
#define int long long
#define F first
#define S second
using namespace std;
const int MAXN=507;
pair<int,int> p[MAXN],q[MAXN];
int n,m,k;

int solve_x(int t)
{
	vector<int>vec;
	vec.push_back(1);
	for(int i=0;i<k;i++)
		if(p[i].F+1+t<=n)
			vec.push_back(p[i].F+t+1);
	
	for(int x:vec)
	{
		vector<pair<int,int> >temp;
		for(int i=0;i<k;i++)
		{
			if(p[i].F-t<=x&&x<=p[i].F+t)
			{
				temp.push_back({p[i].S-t,1});
				temp.push_back({p[i].S+t+1,-1});
			}
		}
		int s=0;
		bool OK=true;
        temp.push_back({1,0});
		sort(temp.begin(),temp.end());
		for(int i=0;i<temp.size();i++)
		{
		    pair<int,int>a=temp[i];
			while(temp[i].F==a.F&&i<temp.size())
			{
				s+=temp[i].S;
				i++;
			}
			i--;
			if(s==0&&a.F<=m)
				OK=false;
		}
		if(OK==false)return x;
	}
	return -1;
}

int solve_y(int t)
{
	vector<int>vec;
	vec.push_back(1);
	for(int i=0;i<k;i++)
		if(q[i].F+1+t<=n)
			vec.push_back(q[i].F+t+1);
	
	for(int x:vec)
	{
		vector<pair<int,int> >temp;
		for(int i=0;i<k;i++)
		{
			if(q[i].F-t<=x&&x<=q[i].F+t)
			{
				temp.push_back({q[i].S-t,1});
				temp.push_back({q[i].S+t+1,-1});
			}
		}
		int s=0;
		bool OK=true;
        temp.push_back({1,0});
		sort(temp.begin(),temp.end());
		for(int i=0;i<temp.size();i++)
		{
		    pair<int,int>a=temp[i];
			while(temp[i].F==a.F&&i<temp.size())
			{
				s+=temp[i].S;
				i++;
			}
			i--;
			if(s==0&&a.F<=n)
				OK=false;
		}
		if(OK==false)return x;
	}
	return -1;
}

bool check(int t)
{
	int x=solve_x(t);
	int y=solve_y(t);
	if(x==-1)
		return true;

	p[k]={
		min(x+t,n),min(y+t,m)
	};
	q[k]={
		min(y+t,m),min(x+t,n)
	};
	
	int t1=k;
	while(t1&&p[t1].F<p[t1-1].F)
	{
		swap(p[t1],p[t1-1]);
		t1--;
	}
	int t2=k;
	while(t2&&q[t2].F<q[t2-1].F)
	{
		swap(q[t2],q[t2-1]);
		t2--;
	}
	k++;
	x=solve_x(t);
	k--;
	
	while(t1!=k)
	{
		swap(p[t1],p[t1+1]);
		t1++;
	}
	while(t2!=k)
	{
		swap(q[t2],q[t2+1]);
		t2++;
	}
	if(x==-1)
		return true;
	else
		return false;
}

int32_t main()
{
	cin>>n>>m>>k;
	for(int i=0;i<k;i++)
	{
		int x,y;
		cin>>x>>y;
		p[i]={x,y};
		q[i]={y,x};
	}
	sort(p,p+k);
	sort(q,q+k);
	
	int l=0,r=1e9+7;
	while(r-l>1)
	{
		int mid=((l+r)/2);
		if(check(mid-1))
			r=mid;
		else 
			l=mid;
	}
	
	cout<<l<<endl;
}