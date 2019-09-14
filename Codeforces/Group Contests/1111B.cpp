#include <bits/stdc++.h>
using namespace std;

int num[100005];

bool cmp(int a,int b){
	return a < b;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n,k,m,mx = -1;
	double sum = 0.0;
	cin >> n >> k >> m;
	for(int i = 0;i < n;++i){
		cin >> num[i];
		mx = max(mx,num[i]);
		sum += num[i];

	} 
	if(m >= n){ //remove all except max
		m -= n - 1;
		k = min(k,m);
		double ans = mx + k;
		cout << fixed << setprecision(10) << ans << "\n";
	} else {
		sort(num,num + n,cmp);
		double avg = ((sum + m) / n);
		int j = m;
		for(int i = 0;i < j;++i){
			avg = max(avg,(double)((sum - num[i] + (double)m - 1.0) / (n - 1)));
			sum -= num[i];
			n--;
			m--;
		}
		cout << fixed << setprecision(10) << avg << "\n";
	}
	
	return 0;
}