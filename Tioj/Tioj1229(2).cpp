#include <cstdio> 
#include <cstring>
int main(){
	int n,len,time,num[105];
	char sen[105],ans[105];
	scanf("%d %d %d",&n,&len,&time);
	for(int i = 0,j;i < len;i++) {
		scanf("%d",&j);
		num[i] = j - 1;
	}
	while(n--){
		scanf("%s",sen);
		for(int j = 0;j < time;j++){
			for(int i = 0;i < len;i++) ans[num[i]] = sen[i];
			for(int i = 0;i < len;i++) sen[i] = ans[i];
		}
		for(int i = 0;i < len;i++) printf("%c",ans[i]);
		printf("\n");
	}
	
	return 0;
}
