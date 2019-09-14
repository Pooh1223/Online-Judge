#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int s[100005];//sequences
int l[100005];//length of s[0...x];

int main(){
	//LIS;
	
	//Initialize;
	printf("Please input your sequence's length.\n");
	int len;
	scanf("%d",&len);
	printf("Now input your sequence's element.\n");
	for(int i = 0;i < len;i++) scanf("%d",&s[i]);	
	for(int i = 0;i < len;i++) l[i] = 1;//everyone is a LIS whose len is 1;

	for(int i = 0;i < len;i++){
		//find the number that could be combined after sequences;
		//if it could,increase the length;
		for(int j = i + 1;j < len;j++){
			if(s[i] < s[j])
				l[j] = max(l[j],l[i] + 1);
		}
	}
	//To find the longest length;
	int n = 0;
	for(int i = 0;i < len;i++){
		n = max(n,l[i]);
	}
	printf("Length of the LIS is : %d\n",n);
	return 0;
}
