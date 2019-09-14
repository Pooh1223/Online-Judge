#include <iostream>
#include <vector>
using namespace std;
vector<int> v;

void chg(int num,int n){
	v.clear();
	while(num >= n){
		v.push_back(num % n);
		num /= n;
	}
	v.push_back(num);
	while(!v.empty()){
		printf("%d",v.back());
		v.pop_back();
	}
}
int main(){
	int n,num;
	scanf("%d%d",&num,&n);
	chg(num,n);
	return 0;
}