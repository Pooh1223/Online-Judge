#include <cstdio>

int main(){
	int t;
	while(~scanf("%d",&t)){
		t %= 7;
		if(t == 0) printf("Friday\n");
		else if(t == 1) printf("Saturday\n");
		else if(t == 2) printf("Sunday\n");
		else if(t == 3) printf("Monday\n");
		else if(t == 4) printf("Tuesday\n");
		else if(t == 5) printf("Wednesday\n");
		else printf("Thursday\n");
	}
	return 0;
}