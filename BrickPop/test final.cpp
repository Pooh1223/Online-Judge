#include <iostream>
using namespace std;

int a[5][5] = {{1,2,2,2,1},{1,1,3,2,1},{2,2,2,2,3},{2,1,1,2,1},{1,1,2,2,1}};
void print(){
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			cout<<a[i][j]<<' ';
		}
		cout<<endl;
	}
	cout<<"over"<<endl;
}
void checkXY(int x,int y,int val){
	if(a[x][y]==val){
		a[x][y]=0;
		if(y!=4)checkXY(x,y+1,val);
		if(y!=0)checkXY(x,y-1,val);
		if(x!=4)checkXY(x+1,y,val);
		if(x!=0)checkXY(x-1,y,val);
	}
}
void drop(){
	for(int i = 4;i >= 0;i--){
		for(int j = 0;j < 5;j++){
			if(a[i][j] == 0){
				for(int k = 1,c;i - k >= 0;k++){
					if(a[i - k][j] != 0){
						c = a[i + k - 1][j];
						a[i + k - 1][j] = a[i - k][j];
						a[i - k][j] = c;
					}
				}
			}
		}
	}
	for(int j = 0;j <= 8;j++){
		for(int i = j;i <= 8;i++){
			if((a[0][i] == 0) && (a[1][i] == 0) && (a[2][i] == 0)
			&& (a[3][i] == 0) && (a[4][i] == 0)){
				for(int k = 0;k < 5;k++){
					a[k][i] = a[k][i + 1];
					a[k][i + 1] = 0;
				}
	    	}
		}
    }
} 
int main(){
	print();
	checkXY(0,1,a[0][1]);
	print();
	drop();
	print();
}
