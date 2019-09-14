#include <iostream>
#include <cstring>
using namespace std;

void aho();
bool check();

int a[2][2];

int main(){
	memset(a , 0 , sizeof(a));
	a[0][1] = 1;
	aho();
	return 0;
}

void aho(){
	int i = 0;
	int j = 0;
	if(a[i][j] == 1 && !check()){
		if(i == 0 && j == 0){
			a[i][j + 1] = 1;
			j++;
			aho();
		}
		else if(i == 0 && j == 2){
			
		}
		else if(i == 2 && j == 0){
			
		}
		else if(i == 2 && j == 2){
			
		}
		else{
			
		}
	}
	check();
}

bool check(){
	for(int i = 0;i < 3;i++){
		for(int j = 0;j < 3;j++){
			if(a[i][j] == 0){
				return 0;
			}
		}
	}
	return 1;
	
	
}
