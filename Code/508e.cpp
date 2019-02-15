#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+7;
stack<int>st;
int p[MAXN],l[MAXN],r[MAXN];
string ans;

int32_t main(){
	int n;scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d%d",&l[i],&r[i]);
	for(int i=0;i<n;i++){
		st.push(i);
		p[i]=ans.size();
		ans+='(';
		int temp=st.top();
		while(st.size()&&p[temp]+l[temp]<=ans.size()){
			if(p[temp]+r[temp]<ans.size())
				return printf("IMPOSSIBLE"),0;
			ans+=')';
			st.pop();
			if(st.size())
				temp=st.top();
		}
	}
	if(st.size())
		printf("IMPOSSIBLE");
	else 
		cout<<ans<<endl;
}