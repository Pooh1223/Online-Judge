#include <iostream>
using namespace std;
struct node{
	int data;
	int mx;
	int mn;
}num[1000005];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		for(int i = 0;i < n;++i){
			cin >> num[i].data;
			if(i == 0) num[i].mx = num[i].data;
			else num[i].mx = max(num[i - 1].data,num[i - 1].mx);
		} 
		for(int i = n - 1;i > 0;--i){
			if(i == n - 1) num[i].mn = num[i].data;
			else num[i].mn = min(num[i + 1].data,num[i + 1].mn);
		}
		int cnt = 0;
		//for(int i = 0;i < n;++i) printf("%d : %d %d %d\n",i,num[i].data,num[i].mx,num[i].mn);
		for(int i = 1;i < n - 1;++i){
			if(num[i].data < num[i].mn && num[i].data > num[i].mx) cnt++;
		}
		cout << cnt << "\n";
	}
	return 0;
}