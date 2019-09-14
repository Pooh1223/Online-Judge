#include <iostream>
using namespace std;
const int len = 8;
int num[] = {0,3,5,7,1,2,6,4,8};
int bit[10];
int lowbit(int a){ return a & -a;}
int query(int n){
	int sum = 0;
	for(int i = n;i > 0;i -= lowbit(i)) sum += bit[i];
	return sum;
}
void modify(int n,int val){
	for(int i = n;i <= len;i += lowbit(i))
		bit[i] += val;
}
void init(int n){//use dp-ish initialize;
	for(int i = 1; i <= n; ++i) {
		bit[i] = num[i];
		int y = i - lowbit(i);
		for(int j = i - 1;j > y;j -= lowbit(j))
			bit[i] += bit[j];
	}
}
int main(){
	//init2
	for(int i = 1;i <= len;++i){
		bit[i] += num[i];
		int k = i + lowbit(i);
		cout << k << "\n";
		if(k <= len) num[k] += num[i];
	}

	for(int i = 1;i <= len;++i){
		cout << bit[i] << " ";
	}	

	return 0;
}