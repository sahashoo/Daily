//for knowing the order if sequens we will get other arr and in each tile we we will add its par and like dsu read it
#include<bits/stdc++.h>
struct Box{int h,w,d;};

int min(int x,int y){return x<y?x:y;}
int max(int x,int y){return x<y?y:x;}

int compare (const void *a,const void *b){
    return ((*(Box*)b).d*(*(Box*)b).w)-((*(Box*)a).d*(*(Box *)a).w);
}

int maxStackHeight(Box arr[],int n){
	Box rot[3*n];
	int index=0;
	for(int i=0;i<n;i++){
		// Copy the original box
		rot[index] = arr[i];
		index++;
	
		// First rotation of box
		rot[index].h=arr[i].w;
		rot[index].d=max(arr[i].h,arr[i].d);
		rot[index].w=min(arr[i].h,arr[i].d);
		index++;
	
		// Second rotation of box
		rot[index].h=arr[i].d;
		rot[index].d=max(arr[i].h, arr[i].w);
		rot[index].w=min(arr[i].h, arr[i].w);
		index++;
	}
	n=3*n;// Now the number of boxes is 3n
	qsort(rot,n,sizeof(rot[0]),compare);
	
	/* Initialize msh values for all indexes 
		msh[i] --> Maximum possible Stack Height with box i on top */
	int msh[n];
	for (int i=0;i<n;i++)msh[i]=rot[i].h;
	/* Compute optimized msh values in bottom up manner */
	for(int i=1;i<n;i++)
		for(int j=0;j<i;j++)
			if(rot[i].w<rot[j].w&&rot[i].d<rot[j].d&&msh[i]<msh[j]+rot[i].h)msh[i]=msh[j]+rot[i].h;
	/* Pick maximum of all msh values */
	int mx=-1;
	for(int i=0;i<n;i++)mx=max(mx,msh[i]);
	return mx;
}

int main(){
  Box arr[] = { {4, 6, 7}, {1, 2, 3}, {4, 5, 6}, {10, 12, 32} };
  int n = sizeof(arr)/sizeof(arr[0]);

  printf("The maximum possible height of stack is %d\n",
         maxStackHeight (arr, n) );

  return 0;
}