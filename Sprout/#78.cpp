#include <cstdio>
int box[7];
bool ck = 0;
int main(){
	while(1){
		for(int i = 1;i < 7;++i){
			scanf("%d",&box[i]);
			if(box[i]) ck = 1;
		}
		if(!ck) break;
		if(box[5]){
			int num = box[5] * 11;
			if(box[1] <= num) box[1] = 0;
			else box[1] -= num; 
		}
		if(box[4]){
			int num = box[4] * 5;
			if(box[2] <= num){
				if(box[1]){
					num -= box[2];
					box[2] = 0;
					num *= 4;
					if(box[1] <= num) box[1] = 0;
					else box[1] -= num;
				}
				else box[2] = 0;
			}
			else box[2] -= num;
		}
		int sum = box[6] + box[5] + box[4];
		int a,b,c;
		a = box[3] % 4;
		b = box[2] % 9;
		c = box[1] % 36;
		//printf("%d %d %d\n",a,b,c);
		sum += box[3] / 4 + box[2] / 9 + box[1] / 36;
		if(a == 0){
			if(b * 4 + c > 36) sum += 2;
			else if(b * 4 + c == 0);
			else if(b * 4 + c <= 36) sum++;
		}
		else if(a == 1){
			if(b == 5){
				if(c <= 7) sum++;
				else sum += 2;
			}
			else if(b > 5){
				if(c <= 7) sum += 2;
				else{
					if((b - 5) * 4 + c - 7 > 36) sum += 3;
					else sum += 2;
				}
			}
			else{
				if(c <= (27 - b * 4)) sum++;
				else sum += 2;
			}
		}
		else if(a == 2){
			if(b == 3){
				if(c <= 6) sum++;
				else sum += 2;
			}
			else if(b > 3){
				if(c <= 6) sum += 2;
				else{
					if((b - 3) * 4 + c - 6 > 36) sum += 3;
					else sum += 2;
				}
			}
			else{
				if(c <= (18 - b * 4)) sum++;
				else sum += 2;
			}
		}
		else{
			if(b == 1){
				if(c <= 5) sum++;
				else sum += 2;
			}
			else if(b > 1){
				if(c <= 5) sum += 2;
				else{
					if((b - 1) * 4 + c - 5 > 36) sum += 3;
					else sum += 2;
				}
			}
			else{
				if(c <= (9 - b * 4)) sum++;
				else sum += 2;
			}
		}
		printf("%d\n",sum);
		ck = 0;
	}
	return 0;
}