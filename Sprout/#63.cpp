#include <cstdio>
#include <cstring>
using namespace std;
int ans[10],in[15];
bool used[15];
int cnt = 0;
void back(int alen,int len,int N){
	if(N == alen + 1){
		for(int i = 1;i < alen + 1;i++){
			if(i == 1) printf("%d",ans[i]);
			else printf(" %d",ans[i]);
		}
		printf("\n");
		return;
	}
	for(int i = 0;i < len;i++){
		if(!used[i]){
			used[i] = 1;
			ans[N] = in[i];
			if(ans[N] < ans[N - 1]){
				used[i] = 0;
				continue;
			}
			back(6,len,N + 1);
			used[i] = 0;
		}
	}
}

int main(){
	int n,cnt = 0;
	while(1){
		scanf("%d",&n);
		if(n == 0) break;
		if(cnt != 0) printf("\n");
		for(int i = 0;i < n;i++) scanf("%d",&in[i]);
		back(6,n,1);
		memset(used,0,sizeof(used));
		memset(ans,0,sizeof(ans));
		memset(in,0,sizeof(in));
		cnt++;
	}
	return 0;
}