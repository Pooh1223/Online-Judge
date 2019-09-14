#include <iostream>
using namespace std;
int p[7122],size[7122];

void init(int n){
	for(int i = 0;i < n;++i){
		p[i] = i;
		size[i] = 1;
	}
}
int find(int n){ return n == p[n] ? n : p[n] = find(p[n]);}
void _union(int a,int b){
	printf("Now union %d and %d.\n",a,b);
	int j = find(a);
	int k = find(b);
	printf("%d's boss is %d while %d's boss is %d.\n",a,j,b,k);
	if(j == k){
		printf("%d and %d are in the same group.\n",a,b);
		return;
	} 
	if(size[j] < size[k]){
		printf("%d's group is smaller,so %d will be in %d's group.\n",a,a,b);
		p[j] = k;
		size[k] += size[j];
	} else {
		printf("%d's group is bigger (or equal to) than %d,so %d will be in %d's group.\n",a,b,b,a);
		p[k] = j;
		size[j] += size[k];
	}
}
int main(){
	int n;
	scanf("%d",&n);
	init(n);
	_union(1,2);
	_union(7,1);
	printf("2's boss is %d.\n",find(2));
	_union(9,8);
	_union(8,5);
	_union(6,9);
	_union(8,7);
	printf("2's boss is %d.\n",find(2));
	_union(1,2);
	_union(1,4);
	printf("1's boss is %d.\n",find(1));
	return 0;
}