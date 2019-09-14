#include <bits/stdc++.h>
using namespace std;

int main(){
	
	vector<long long> v;
	v.push_back(1);
	while(v.size() != 1500){
		long long n1,n2,n3;
		for(int i = 0;i < v.size();++i){
			if(v[i] * 2 > v[v.size() - 1]){
				n1 = v[i] * 2;
				break;
			}
		}
		for(int i = 0;i < v.size();++i){
			if(v[i] * 3 > v[v.size() - 1]){
				n2 = v[i] * 3;
				break;
			}
		}
		for(int i = 0;i < v.size();++i){
			if(v[i] * 5 > v[v.size() - 1]){
				n3 = v[i] * 5;
				break;
			}
		}

		v.push_back(min(n1,min(n2,n3)));
	}
	cout << "The 1500'th ugly number is " << v[1499] << ".\n";
	return 0;
}