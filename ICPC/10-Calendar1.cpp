#include <cstdio>
using namespace std;
int d[10];
int main(){
	bool ck = 0;
	for(int i = 0;i < 7;++i) scanf("%d",&d[i]);
	for(int i = 0;i < 7;++i){
		if(d[i] > 31){
			ck = 1;
			//printf("1\n");
			break;
		}
		if(i != 0 && d[i] - d[i - 1] != 1){
			if(d[i] != 1){
				ck = 1;
				//printf("2\n");
				break;
			} else if(d[i - 1] > 31 || d[i - 1] < 28){
				ck = 1;
				//printf("3\n");
				break;
			}
		}
	}

	if(ck) printf("Impossible\n");
	else printf("Possible\n");

	return 0;
}