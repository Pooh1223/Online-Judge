#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int n;
	cin >> n;
	while(n--){
		int len;
		cin >> len;
		if(!len) continue;
		int num[len],sum = 0;
		for(int i = 0;i < len;i++){
			cin >> num[i];
		}
		sort(num,num + len);
		reverse(num,num + len);
		for(int j = 0;j < len;j++){
			if(num[j] - (j + 1) > 0) sum += (num[j] - (j + 1));
			else break;
		}
		cout << sum << endl;
	}
	return 0;
}
