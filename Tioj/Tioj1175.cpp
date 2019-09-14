#include <iostream>
#include <vector>
using namespace std;

int lis(vector<int>& k){
	if(!k.size()) return 0;
	
	vector<int> v;
	v.push_back(k[0]);
	
	for(int i = 1;i < k.size();i++){
		int n = k[i];
		if(n > v.back()) v.push_back(n);
		else *lower_bound(v.begin(),v.end(),n) = n;
	}
	return v.size();
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	vector<int> num;
	int n,a;
	cin >> n;
	while(n--){
		cin >> a;
		num.push_back(a);
	}
	cout << lis(num) << "\n";
} 
