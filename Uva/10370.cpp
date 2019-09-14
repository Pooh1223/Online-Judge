#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	scanf("%d",&n);
	while(n--){
		int t;
		scanf("%d",&t);
		int stu[1003];
		float avg = 0;
		for(int i = 0;i < t;++i){
			scanf("%d",&stu[i]);
			avg += stu[i];
		} 
		avg /= t;

		int cnt = 0;
		for(int i = 0;i < t;++i){
			if(stu[i] > avg) cnt++;
		}
		printf("%.3f%\n",(float)cnt * 100.0 / (float)t);
	}
	
	return 0;
}