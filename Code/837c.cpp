#include<bits/stdc++.h>
#define S second
#define F first
using namespace std;
const int N=2e5+7;
int n,a,b;
pair<int,int>arr[N];
vector<int>v;

bool check(pair<int,int>p1,pair<int,int>p2){
	int x=b,y=a;
	//normal
	if(max(p1.F,p2.F)<=a&&p1.S+p2.S<=b)return true;
	//p1 rotated
	swap(p1.F,p1.S);
	if(max(p1.F,p2.F)<=a&&p1.S+p2.S<=b)return true;
	//both rotated
	swap(p2.F,p2.S);
	if(max(p1.F,p2.F)<=a&&p1.S+p2.S<=b)return true;
	//p2 rotated
	swap(p1.F,p1.S);
	if(max(p1.F,p2.F)<=a&&p1.S+p2.S<=b)return true;
	//x y rotated
	swap(p2.F,p2.S);
	if(max(p1.F,p2.F)<=x&&p1.S+p2.S<=y)return true;
	swap(p1.F,p1.S);
	if(max(p1.F,p2.F)<=x&&p1.S+p2.S<=y)return true;
	swap(p2.F,p2.S);
	if(max(p1.F,p2.F)<=x&&p1.S+p2.S<=y)return true;
	swap(p1.F,p1.S);
	if(max(p1.F,p2.F)<=x&&p1.S+p2.S<=y)return true;
	
	return false;
}

int32_t main(){
	cin>>n>>a>>b;
	for(int i=0;i<n;i++)cin>>arr[i].F>>arr[i].S;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(check(arr[i],arr[j])){
				v.push_back((arr[i].F*arr[i].S)+(arr[j].F*arr[j].S));
			}
		}
	}
	sort(v.begin(),v.end());
	// for(int i=0;i<v.size();i++)cout<<v[i]<<" ";
	// cout<<endl;
	cout<<(v.empty()?0:v.back());
}