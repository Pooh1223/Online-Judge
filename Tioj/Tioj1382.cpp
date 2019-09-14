#include <cstdio>
#define ll long long
using namespace std;
bool used[100005];
ll sum[100005],num;
int main(){
	int n;
	while(1){
		scanf("%d",&n);
		if(n == EOF) break;
		for(int i = 0;i < n;++i){
			scanf("%lld",&sum[i]);
			sum[i] += num;
			num = sum[i];
		}
		int cnt = 1;
		int id = 0;
		for(int i = 1;;++i){
			if(i > n) i -= n;
			if(used[i] == 0){
				if(sum[id] == cnt){
					printf("%d ",i);
					id++;
					used[i] = 1;
				} 
				cnt++;
			}
			if(id == n){
				//printf("yee\n");
				break;
			} 
		}
	}
	return 0;
}