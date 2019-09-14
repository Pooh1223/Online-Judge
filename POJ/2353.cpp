#include <iostream>
using namespace std;
int num[35005]; //less than n'sum ;
int qq[15005]; //level sum;
#define lowbit(i) i & (-i)

int sum(int n){
	int s = 0;
	while(n > 0){
		s += num[n];
		n -= lowbit(n);
	}
	return s;
}
void update(int n,int val){ //val = newvalue - oldvalue,in this Q,val must be 1;
	while(n <= 32005){
		num[n] += val;
		n += lowbit(n);
	}
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 0;i < n;++i){
		int x,y;
		cin >> x >> y;
		qq[sum(++x)]++;
		update(x,1);
	}
	for(int i = 0;i < n;++i) cout << qq[i] << "\n";
	return 0;
}