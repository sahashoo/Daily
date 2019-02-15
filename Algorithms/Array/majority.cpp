#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=1e6+1;
const int delta=10037;
const int N=1e5+7;


int find_majority(vector<int>& vec)
{
	int ind=0,cnt=1;
	for(int i=1;i<vec.size();i++)
	{
		if(vec[ind]==vec[i])cnt++;
		else cnt--;
		if(cnt==0)
			ind=i,cnt=1;
	}
	return vec[ind];
}

int32_t main()
{
	vector<int>a={1,2,3,5,5,5};
	cout<<find_majority(a)<<endl;
	
	return cout<<endl,0;	
}
