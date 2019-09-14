#include<stdio.h> 
#include<stdlib.h>
int main() { 
	int i,j,num; 
	while(1){
		printf("Please input number: "); 
	scanf("%d",&num); 
	
	printf("%d½è¼Æ¦³:\n",num); 
	
	for(i=2; i<=num; i++){  
		for(j=2; j<=i; j++){ 
			if(i%j==0)break; 
		}	 
		if(i==j) 
		printf("%-2d",i); 
	} 
	printf("\n"); 
	system("pause");
	}
	 
	return 0; 
} 
