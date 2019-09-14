#include <bits/stdc++.h>
using namespace std;
int num[2003];
vector<int> v;
int gcd(int x,int y){
	while(1){
		x %= y;
		if(x) y %= x;
		if(!x) return y;
		else if(!y) return x;
	}
}
int main(){
	int n;
	cin >> n;
	for(int i = 0;i < n;++i){
		int j;
		cin >> j;
		v.push_back(j);
	}
	int cnt = 0;
	bool ck = 1;
	int len1 = v.size(),len2 = 0;
	while(ck){
		v.clear();
		for(int i = 1;i < n;++i){
			v.push_back(gcd(v[i - 1],v[i]));
			if(v.back() == 1){ck = 0;break;}
		}
		cnt++;
		len2 = v.size();
		if(len1 == len2) return cout << "-1\n",0;
		len1 = len2;
	}
	cnt += n - 1;
	cout << cnt << "\n";
	return 0;
}