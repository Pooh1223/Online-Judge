#include <cstdio>
int num[1000005],a[1000005];
void merge(int l,int r){
	if(r - l == 1) return;
	int m = (l + r) / 2;
	merge(l,m);
	merge(m,r);
	int left = l,right = m,k = l;
	while(left < m || right < r){
		if(left < m && (right >= r || num[left] < num[right])) a[k++] = num[left++];
		else a[k++] = num[right++];
	}
	for(int i = l;i < r;++i) num[i] = a[i];
}
int main(){
	int n;
	while(~scanf("%d",&n)){
		if(n == 0) break;
		for(int i = 0;i < n;++i) scanf("%d",&num[i]);
		merge(0,n);
		for(int i = 0;i < n;++i){
			if(i == 0) printf("%d",num[i]);
			else printf(" %d",num[i]);
		} 
		printf("\n");
	}
	return 0;
}