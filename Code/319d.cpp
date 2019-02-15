///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define int long long
using namespace std;
char s[500000];
int n;

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	scanf("%s",s);
	n=strlen(s);
	int pos=1;
	while(1){
		if(pos>n/2)break;
		int found=-1;
		for(int j=0;j+2*pos<=n;j++){
			int i=j+pos,OK=0;
			while(OK<pos){
				if(s[i+OK]!=s[j+OK])break;
				OK++;
			}
			if(OK==pos){
				found=j;
				break;
			}
		}
		if(found==-1)pos++;
		else{
			for(int j=found+pos;j<n-pos;j++)s[j]=s[j+pos];
			n-=pos;
			s[n]='\0';
		}
	}
	int i=0;
	printf("%s",s);
}
