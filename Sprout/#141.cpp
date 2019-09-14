#include <iostream>
#include <cstring>
using namespace std;
int num[100005],ans[100005];
inline int f(int len){
	if(len <= 2) return ans[len] = num[len];
	if(ans[len]) return ans[len];
	return ans[len] = num[len] + max(f(len - 2),f(len - 3));
}
int main(){
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		for(int i = 1;i <= n;++i) cin >> num[i];
		if(n == 1) cout << num[1] << "\n";
		else if(n == 2) cout << max(num[1],num[2]) << "\n";
		else if(n == 3) cout << max(num[1] + num[3],num[2]) << "\n";
		else cout << max(f(n),f(n - 1)) << "\n";
		memset(ans,0,sizeof(ans));
	}
	return 0;
}